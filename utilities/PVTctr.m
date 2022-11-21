classdef PVTctr < matlab.System
    % read PID para once and hold for dispaly, will read once at the start

    % Pre-computed constants
    properties(Access = private)
        EnNumOld;
        count;
        cmdENOld;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.EnNumOld=0;
            obj.count=0;
            obj.cmdENOld=0;
        end

        function [cmd,cmdEN] = stepImpl(obj,EnNum,PVTdes)
            % PVTdes: desier pos, deg 
            %         desier vel, deg per sec
            %         desier torque, A

            % PVTdes: desier pos, 0.1deg / one number
            %         desier vel, 1 deg per sec / one number
            %         desier torque, 66A/4096 / one number

            if obj.count<0.5
                obj.EnNumOld=EnNum;
            end

            if obj.EnNumOld~=EnNum
                cmdEN=1;
            else
                cmdEN=0;
            end
            cmd=uint8(zeros(8,1));
            cmd(1)=0xae;
            cmd(2)=0;
            tmp=typecast(int16(PVTdes(1)/0.01),'uint8');
            cmd(3)=tmp(1);
            cmd(4)=tmp(2);
            tmp=typecast(int16(PVTdes(2)),'uint8');
            cmd(5)=tmp(1);
            cmd(6)=tmp(2);
            tmp=typecast(int16(PVTdes(3)*4096/66),'uint8');
            cmd(7)=tmp(1);
            cmd(8)=tmp(2);

            obj.cmdENOld=cmdEN;
            obj.EnNumOld=double(EnNum);
            obj.count=obj.count+1;
            if obj.count>10
                obj.count=10;
            end
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

        function num = getNumOutputsImpl(~)
            num = 2;
        end

        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
            varargout{2} = true;
        end


        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
            varargout{2} = false;
        end

        function varargout = getOutputSizeImpl(~)
            varargout{1} = [8,1];
            varargout{2} = [1,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
            varargout{2} = 'double';
        end
    end
end
