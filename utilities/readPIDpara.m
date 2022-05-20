classdef readPIDpara < matlab.System
    % read PID para once and hold for dispaly, will read once at the start

    % Pre-computed constants
    properties(Access = private)
        EnNumOld;
        count;
        cmdENOld;
        pos_PI;
        spd_PI;
        cur_PI;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.EnNumOld=0;
            obj.count=0;
            obj.pos_PI=[0;0];
            obj.spd_PI=[0;0];
            obj.cur_PI=[0;0];
            obj.cmdENOld=0;
        end

        function [cmd,PID_read,cmdEN] = stepImpl(obj,EnNum,rawData)
            % PID_read: P,I for position loop
            %           P,I for speed loop
            %           P,I for current loop
%             if obj.count<0.5
%                 obj.EnNumOld=EnNum;
%             end

            if obj.EnNumOld~=EnNum
                cmdEN=1;
            else
                cmdEN=0;
            end
            cmd=uint8(zeros(8,1));
            cmd(1)=0x30;
            if obj.cmdENOld>0.5 && typecast(rawData(1),'uint8')==0x30
                obj.pos_PI(1)=double(typecast(rawData(3),'uint8'));
                obj.pos_PI(2)=double(typecast(rawData(4),'uint8'));
                obj.spd_PI(1)=double(typecast(rawData(5),'uint8'));
                obj.spd_PI(2)=double(typecast(rawData(6),'uint8'));
                obj.cur_PI(1)=double(typecast(rawData(7),'uint8'));
                obj.cur_PI(2)=double(typecast(rawData(8),'uint8'));
            end
            PID_read=[obj.pos_PI;obj.spd_PI;obj.cur_PI];


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
            varargout{2} = [6,1];
            varargout{3} = [1,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'uint8';
            varargout{2} = 'double';
            varargout{3} = 'double';
        end
    end
end
