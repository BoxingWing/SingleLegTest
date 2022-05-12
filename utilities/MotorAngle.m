classdef MotorAngle < matlab.System
    % calibrate and output the motor angle

    % Public, tunable properties
    properties(Nontunable)
        angleOff=0;
    end

    % Pre-computed constants
    properties(Access = private)
        calibrated=false;
        loop_count=0;
        speed_prev=ones(10,1)*99;
        sgl_angle_old=0;
    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function [abs_angle,calibration] = stepImpl(obj,speed,sgl_angle,pos_des)
            % speed: unit in LSB
            if obj.calibrated==false
                abs_angle=0;
            else
                if sgl_angle-obj.sgl_angle_old<-180
                    obj.loop_count=obj.loop_count+1;
                elseif sgl_angle-obj.sgl_angle_old>180
                    obj.loop_count=obj.loop_count-1;
                end
                abs_angle=sgl_angle/6+obj.loop_count*60;
            end
            if obj.calibrated==false
                motor_stop=true;
                ava=0;
                for i=1:1:length(obj.speed_prev)
                    ava=ava+obj.speed_prev(i)^2;
                end
                ava=ava/length(obj.speed_prev);
                if ava<0.02
                    motor_stop=true;
                else
                    motor_stop=false;
                end
                if motor_stop==true && pos_des==0
                     if sgl_angle>=0 && sgl_angle<=180
                         obj.loop_count=0;
                     else
                         obj.loop_count=-1;
                     end
                    obj.calibrated=true;
                end
            end
            abs_angle=abs_angle+obj.angleOff;
            calibration=obj.calibrated;
            obj.sgl_angle_old=sgl_angle;
            obj.speed_prev(1:end-1)=obj.speed_prev(2:end);
            obj.speed_prev(end)=speed;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
    end
end
