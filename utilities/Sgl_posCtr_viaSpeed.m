classdef Sgl_posCtr_viaSpeed < matlab.System
    % position control for 1 motors via speed control

    properties
        dt=0.005;
    end
    % Pre-computed constants
    properties(Access = private)
        posOld;
        count;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.posOld=0;
            obj.count=0;
        end

        function cmd = stepImpl(obj,pos,speed,calFlag)
            % angle : position after the reducer, degree
            % speed : speed after the reducer, degree per second
            if obj.count==0
                obj.posOld=pos;
                obj.count=1;
            end
            desSpeed=(pos-obj.posOld)/obj.dt;
            if abs(desSpeed)<0.5
                speedEN=false;
            else
                speedEN=true;
            end
            if calFlag<0.5
                pos=0;
                speed=8;
            end
            cmd=uint8(zeros(8,1));
            if speedEN
                cmd(1)=0xa2;
                cmd(5:8)=typecast(int32(floor(desSpeed*6*100)),'uint8');
            else
                idx=1;
                cmd(idx)=0xa4;
                cmd(idx+2:idx+3)=typecast(uint16(floor(speed*6)),'uint8');
                cmd(idx+4:idx+7)=typecast(int32(floor(pos*6*100)),'uint8');
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
