classdef Multi_posCtr < matlab.System
    % position control and offset set. change the input to send offset command
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.


    % Pre-computed constants
    properties(Access = private)

    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function cmd = stepImpl(obj,pos_arr,speed_arr)
            % Implement algorithm. Calculate y as a function of input u and
            % discrete states.

            cmd=uint8(zeros(24,1));
            for i=1:1:3
                idx=i*8-7;
                cmd(idx)=0xa4;
                cmd(idx+2:idx+3)=typecast(uint16(floor(speed_arr(i))),'uint8');
                cmd(idx+4:idx+7)=typecast(int32(floor(pos_arr(i)*6*100)),'uint8');
            end
            

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
            varargout{1} = [24,1];
        end
        
        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
        end
    end
end
