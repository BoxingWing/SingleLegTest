classdef Multi_posCtr_speedLoop < matlab.System
    % position control for 3 motors via speed loop
    properties
        dt=0.004;
        k_errPos=0.8;
    end
    
    % Pre-computed constants
    properties(Access = private)
        count=0;
        pos_arr_old=zeros(3,1);
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.count=0;
        end

        function cmd = stepImpl(obj,pos_arr,speed_arr,posFB,cabFlag)
            % angle : position after the reducer, degree
            % speed : speed after the reducer, degree per second
            if obj.count<1
                obj.pos_arr_old(1)=pos_arr(1);
                obj.pos_arr_old(2)=pos_arr(2);
                obj.pos_arr_old(3)=pos_arr(3);
                obj.count=1;
            end
            pos_err=pos_arr-posFB;
            for i=1:1:3
                if abs(pos_err(i))<1
                    pos_err(i)=0;
                end
            end
            speedCp=(pos_arr-posFB)*obj.k_errPos/obj.dt;
            desSpeed=(pos_arr-obj.pos_arr_old)/obj.dt+speedCp;
            speedEN=[false;false;false];
            for i=1:1:3
                if abs(desSpeed(i))<0.1 || cabFlag(i)<0.5
                    speedEN(i)=false;
                else
                    speedEN(i)=true;
                end
            end
            cmd=uint8(zeros(24,1));
            for i=1:1:3
                idx=i*8-7;
                if speedEN(i)
                    cmd(idx)=0xa2;
                    cmd(idx+4:idx+7)=typecast(int32(floor(desSpeed(i)*6*100)),'uint8');
                else
                    cmd(idx)=0xa4;
                    cmd(idx+2:idx+3)=typecast(uint16(floor(speed_arr(i)*6)),'uint8');
                    cmd(idx+4:idx+7)=typecast(int32(floor(pos_arr(i)*6*100)),'uint8');
                end
            end
            
            obj.pos_arr_old(1)=pos_arr(1);
            obj.pos_arr_old(2)=pos_arr(2);
            obj.pos_arr_old(3)=pos_arr(3);
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
