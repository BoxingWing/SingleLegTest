classdef FK_sgl < matlab.System
    % 2D forward kinematic for single leg.
    properties
        upper_stiff=1;
        lower_stiff=1;
    end
    % Pre-computed constants
    properties(Access = private)
        AC=0.2;
        BE=0.13;
        DG=0.2;
        CD=0.07;
        FG=0.1; % will be updated in the setup function
        GH=0.2;
        CDG=3.2563;
        FGH=-3.1915;
        STO=0;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.FG=obj.AC-obj.BE;
            obj.STO=0;
        end

        function [pH,fe,BDG,DGH,td] = stepImpl(obj,theta2,theta3,encoderArray,motorCab)
        % theta2: NO.2 motor angle, controlling the leg angle, unit: rad
        % theta3: NO.3 motor angle, controlling the leg length, unit: rad
        % encoderArry: passive joint angle feedback
        % pH: feedback footend position considering the feedback motor
        %        angles and the passive joint angles.

        
        CDGnow=-(theta3-pi/2)+encoderArray(1);
        FGHnow=-pi+encoderArray(1)+encoderArray(2);

        [pH,~,~]=LegFK(obj.AC,obj.BE,obj.CD,CDGnow,obj.DG, ...
                obj.FG,FGHnow,obj.GH,theta2,theta3);
        [~,BDG,DGH]=LegFK(obj.AC,obj.BE,obj.CD,obj.CDG,obj.DG, ...
                obj.FG,obj.FGH,obj.GH,theta2,theta3);
        pHnor=LegFK(obj.AC,obj.BE,obj.CD,obj.CDG,obj.DG, ...
                obj.FG,obj.FGH,obj.GH,theta2,theta3);
%         if (pH(2)-pHnor(2))>0.005 || encoderArray(1)-BDG>0.04 && obj.STO<0.5
%             td=1;
%         else
%             td=0;
%         end
        if encoderArray(1)-BDG>0.03 && obj.STO<0.5
            td=1;
        else
            td=0;
        end

        if abs(encoderArray(1)-BDG)>30/180*pi && abs(encoderArray(2)-DGH)>30/180*pi && ...
                sum(motorCab)>2.5
            obj.STO=1;
        end
        
        if obj.STO>0.5
            td=0;
        end

        dpH_pj = LegJac_PJ_embedded(obj.AC,obj.BE,CDGnow,obj.DG,obj.FG,FGHnow,obj.GH,theta2,theta3-pi/2);
        fe=pinv(dpH_pj')*diag([obj.upper_stiff,obj.lower_stiff])*[CDGnow-obj.CDG;FGHnow-obj.FGH];
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

%                 function num = getNumOutputsImpl(~)
%                     num = 2;
%                 end
%         
%                 function varargout = isOutputFixedSizeImpl(~,~)
%                     varargout{1} = true;
%                     varargout{2} = true;
%                 end
%         
%         
%                 function varargout = isOutputComplexImpl(~)
%                     varargout{1} = false;
%                     varargout{2} = false;
%                 end
%         
%                 function varargout = getOutputSizeImpl(~)
%                     varargout{1} = [1,1];
%                     varargout{2} = [1,1];
%                 end
%         
%                 function varargout = getOutputDataTypeImpl(~)
%                     varargout{1} = 'double';
%                     varargout{2} = 'double';
%                 end
    end
end
%% subfunction
function [pH,BDG,DGH]=LegFK(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)
% BDG: angle from BD extension line to DG, normally positive
% DGH: angle from DG extension line to GH, normally negative
    theta2=theta2-pi/2;
    pB=[0;0];
    pD=Rz2D(theta1)*[0;-AC];
    pA=Rz2D(theta2)*CD/AC*(pD-pB)+pB;
    pC=pA+pD-pB;
    pE=Rz2D(theta1)*[0;-BE];
    pG=Rz2D(CDG)*DG/CD*(pC-pD)+pD;
    pF=pE+pG-pD;
    pH=Rz2D(FGH)*GH/FG*(pF-pG)+pG;
    BDG=real(acos((pG-pD)'*(pD-pB)/AC/DG));
    DGH=real(-acos((pH-pG)'*(pG-pD)/DG/GH));
end

function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end

function dpH_pj = LegJac_PJ_embedded(AC,BE,CDG,DG,FG,FGH,GH,theta1,theta2)
%LegJac_PJ
%    dpH_pj = LegJac_PJ(AC,BE,CDG,DG,FG,FGH,GH,THETA1,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    11-May-2022 16:41:43

t2 = FGH+theta1;
t3 = CDG+theta1+theta2;
t4 = -BE;
t5 = 1.0./FG;
t6 = AC+t4;
dpH_pj = reshape([DG.*cos(t3),DG.*sin(t3),-GH.*t5.*t6.*cos(t2),-GH.*t5.*t6.*sin(t2)],[2,2]);
end