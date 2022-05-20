classdef stopMotor < matlab.System
    % stop the motor for emergency 

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

        function [cmd,cmdEN] = stepImpl(obj,EnNum)
            if obj.count<0.5
                obj.EnNumOld=EnNum;
            end
            if obj.EnNumOld~=EnNum || obj.cmdENOld>0.5
                cmdEN=1;
            else
                cmdEN=0;
            end
            cmd=uint8(zeros(8,1));
            cmd(1)=0x81;

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
