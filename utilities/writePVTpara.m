classdef writePVTpara < matlab.System
    % write PVT para to RAM once and hold for dispaly
    
    properties

    end

    % Pre-computed constants
    properties(Access = private)
        EnNumOld;
        count;
        cmdENOld;
        kp_Old;
        kd_Old;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.EnNumOld=0;
            obj.count=0;
            obj.kp_Old=0;
            obj.kd_Old=0;
            obj.cmdENOld=0;
        end

        function [cmd,paraSet,cmdEN] = stepImpl(obj,EnNum,pdArray)
            % pidArray: kp for position loop
            %           kd for speed loop
            if obj.count<0.5
                obj.EnNumOld=EnNum;
            end
            if obj.EnNumOld~=EnNum
                cmdEN=1;
                obj.kp_Old=pdArray(1);
                obj.kd_Old=pdArray(2);
            else
                cmdEN=0;
            end
            cmd=uint8(zeros(8,1));
            cmd(1)=0xaf;
            cmd(2)=0x01;
            tmp=typecast(int16(obj.kp_Old),'uint8');
            cmd(3)=tmp(1);
            cmd(4)=tmp(2);
            tmp=typecast(int16(obj.kd_Old),'uint8');
            cmd(5)=tmp(1);
            cmd(6)=tmp(2);
            
            paraSet=[obj.kp_Old;obj.kd_Old];

            obj.cmdENOld=cmdEN;
            obj.EnNumOld=EnNum;
            obj.count=obj.count+1;
            if obj.count>10
                obj.count=10;
            end
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

        function num = getNumOutputsImpl(~)
            num = 3;
        end

        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
            varargout{2} = true;
            varargout{3} = true;
        end


        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
            varargout{2} = false;
            varargout{3} = false;
        end

        function varargout = getOutputSizeImpl(~)
            varargout{1} = [8,1];
            varargout{2} = [2,1];
            varargout{3} = [1,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
            varargout{2} = 'double';
            varargout{3} = 'double';
        end
    end
end
