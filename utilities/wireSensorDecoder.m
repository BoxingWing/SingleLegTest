classdef wireSensorDecoder < matlab.System
    % calibrate and output the wire sensor length

    %     % Public, tunable properties
    %     properties(Nontunable)
    %         angleOff=0;
    %     end

    % Pre-computed constants
    properties(Access = private)
        wireAngleOld=zeros(3,1);
        errOld;
        count;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.count=0;
        end

        function pos = stepImpl(obj,rawData,err,recvID)
            % pos: unit meter
            wireangle=obj.wireAngleOld;

            IDFlag=abs(recvID(1)-0x182)<0.1;
            if err<1 && obj.errOld<1 && IDFlag
                wireAngle=-double(typecast(rawData(1:4),'uint32'))/4096*360;
                if obj.count<1
                    obj.wireAngleOld=wireAngle;
                    obj.count=2;
                end
            end
            
            pos=wireangle/360*200/1000;

            obj.wireAngleOld=wireangle;
            obj.errOld=err;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
