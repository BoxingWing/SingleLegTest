classdef Sgl_posCtr < matlab.System
    % position control for 1 motors


    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function cmd = stepImpl(obj,pos,speed,calFlag)
            % angle : position after the reducer, degree
            % speed : speed after the reducer, degree per second
            if calFlag<0.5
                pos=0;
                speed=8;
            end
            cmd=uint8(zeros(8,1));
            idx=1;
            cmd(idx)=0xa4;
            cmd(idx+2:idx+3)=typecast(uint16(floor(speed*6)),'uint8');
            cmd(idx+4:idx+7)=typecast(int32(floor(pos*6*100)),'uint8');

        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end

        function num = getNumOutputsImpl(~)
            num = 1;
        end

        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
        end


        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
        end

        function varargout = getOutputSizeImpl(~)
            varargout{1} = [8,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
        end
    end
end
