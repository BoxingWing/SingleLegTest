classdef encoder_servo_quest < matlab.System
    % position control and offset set. change the input to send offset command
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.


    % Pre-computed constants
    properties(Access = private)
        %offset_Num=0;
        %itr_count=0;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function cmd = stepImpl(obj,servo_pos_des,servoEN,servoReset)
            cmd=uint8(zeros(16,1));
            if servoEN>0.5
                cmd(9)=1;
            elseif servoReset>0.5
                cmd(9)=2;
            end
            cmd(11:14)=typecast(uint32(floor(servo_pos_des/(360.0/4096.0))),'uint8');
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
            varargout{1} = [16,1];
        end
        
        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
        end
    end
end
