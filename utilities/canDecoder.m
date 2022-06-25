classdef canDecoder < matlab.System
    % calibrate and output the motor angle

    %     % Public, tunable properties
    %     properties(Nontunable)
    %         angleOff=0;
    %     end

    % Pre-computed constants
    properties(Access = private)
        angleOld=zeros(3,1);
        speedOld=zeros(3,1);
        currentOld=zeros(3,1);
        encoderOld=zeros(2,1);
        errOld=0;
        count=0;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.count=0;
        end

        function [angle,speed,current,encoder] = stepImpl(obj,rawData,err)
            angle=obj.angleOld;
            speed=obj.speedOld;
            current=obj.currentOld;
            encoder=obj.encoderOld;

            if err==0 && obj.errOld==0
                for i=1:1:3
                    idx=i*8-7;
                    angle(i) = double(typecast(rawData(idx+6:idx+7),'uint16'))/65535*360;
                    speed(i) = double(typecast(rawData(idx+4:idx+5),'int16'))/6;
                    current(i) = double(typecast(rawData(idx+2:idx+3),'int16'));
                end
                rowEnd=rawData(25:32);
                encoder(2)=-double(typecast(rowEnd(1:2),'uint16'))/65536*360;
                encoder(1)=-double(typecast(rowEnd(3:4),'uint16'))/65536*360;
                if obj.count<1
                    obj.encoderOld=encoder;
                    obj.count=2;
                end
                if abs(encoder(1)-obj.encoderOld(1))>10
                    encoder(1)=obj.encoderOld(1);
                end
                if abs(encoder(2)-obj.encoderOld(2))>10
                    encoder(2)=obj.encoderOld(2);
                end
            end
            obj.angleOld=angle;
            obj.speedOld=speed;
            obj.currentOld=current;
            obj.encoderOld=encoder;
            obj.errOld=err;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
