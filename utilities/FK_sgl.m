classdef FK_sgl < matlab.System
    % 2D forward kinematic for single leg.

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
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.FG=obj.AC-obj.BE;
        end

        function [pH,BDG,DGH] = stepImpl(obj,theta2,theta3)
        % theta2: NO.2 motor angle, controlling the leg angle, unit: rad
        % theta3: NO.3 motor angle, controlling the leg length, unit: rad

            [pH,BDG,DGH]=LegFK(obj.AC,obj.BE,obj.CD,obj.CDG,obj.DG, ...
                obj.FG,obj.FGH,obj.GH,theta2,theta3);
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