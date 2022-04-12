classdef posCtr_and_offset < matlab.System
    % position control and offset set. change the input to send offset command
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.


    % Pre-computed constants
    properties(Access = private)
        offset_Num=0;
        itr_count=0;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function cmd = stepImpl(obj,pos_des,speed_des,set_Offset_Num)
        % pos_des: degree of the final output, degree
        % speed_des: speed of the final output, degree per second
            if obj.itr_count<1
                obj.offset_Num=set_Offset_Num;
            end
            cmd=uint8(zeros(8,1));
            if set_Offset_Num~=obj.offset_Num
                cmd(1)=0x19;
                obj.offset_Num=set_Offset_Num;
            else
                cmd(1)=0xa4;
                cmd(3:4)=typecast(uint16(floor(speed_des*6)),'uint8');
                cmd(5:8)=typecast(int32(floor(pos_des*6*100)),'uint8');
            end
            if obj.itr_count<100
            obj.itr_count=obj.itr_count+1;
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
            varargout{1} = [8,1];
        end
        
        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
        end
    end
end
