classdef jump_closed< matlab.System
    % closed-loop jump trajectory generation
    
    properties
        tsk=0.15; % shrink time
        tst=0.05; % strentch time
        tst_wt=0.1; % strentch wait time 
        tdy=0.05; % touch event wait
        lh=0.07; % strentch length
        zOff=-0.5;
    end

    properties(Nontunable)
        SampleTime = 0.004; % Sample Time
        OffsetTime = 0; % Offset Time
        TickTime = 0;
        SampleTimeTypeProp (1, 1) {mustBeMember(SampleTimeTypeProp, ...
            ["Discrete","FixedInMinorStep","Controllable",...
            "Inherited","InheritedNotControllable",...
            "InheritedErrorConstant"])} = "Discrete"
    end
    
    properties(Access = private)
        curState=0;
        timeAcu0=0;
        timeAcu2=0;
        ENFlag=0;
        ENold=0;
        count=0;
    end
    
    methods(Access = protected)
        function sts = getSampleTimeImpl(obj)
            switch char(obj.SampleTimeTypeProp)
                case 'Inherited'
                    sts = createSampleTime(obj,'Type','Inherited');
                case 'InheritedNotControllable'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'AlternatePropagation','Controllable');
                case 'InheritedErrorConstant'
                    sts = createSampleTime(obj,'Type','Inherited',...
                        'ErrorOnPropagation','Constant');
                case 'FixedInMinorStep'
                    sts = createSampleTime(obj,'Type','Fixed In Minor Step');
                case 'Discrete'
                    sts = createSampleTime(obj,'Type','Discrete',...
                        'SampleTime',obj.SampleTime, ...
                        'OffsetTime',obj.OffsetTime);
                case 'Controllable'
                    sts = createSampleTime(obj,'Type','Controllable',...
                        'TickTime',obj.TickTime);
            end
        end
        
        function setupImpl(obj)
            obj.curState=0;
            obj.count=0;
            obj.ENFlag=0;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
        end
        
        function [zTra,isStill] = stepImpl(obj,EN,tdFlag)
        % curstate: 0 -> leg shrink
        %           1 -> wait touch
        %           2 -> wait, strentch and wait
        if obj.count<0.5
            obj.ENold=EN;
            obj.count=1;
        end
        if obj.ENold~=EN
            obj.ENFlag=obj.ENFlag+1;
            obj.ENFlag=mod(obj.ENFlag,2);
            obj.ENold=EN;
        end
        if obj.curState==0
            zTra=obj.zOff+sin(obj.timeAcu0/obj.tsk/2*pi)*obj.lh;
            obj.timeAcu0=obj.timeAcu0+obj.SampleTime;
        elseif obj.curState==1
            zTra=obj.zOff+obj.lh;
        else
            if obj.timeAcu2<=obj.tdy
                zTra=obj.zOff+obj.lh;
            elseif obj.timeAcu2>obj.tdy && obj.timeAcu2<=obj.tdy+obj.tst
                zTra=obj.zOff+sin((obj.timeAcu2-obj.tdy) ...
                    /obj.tst/2*pi+pi/2)*obj.lh;
            else
                zTra=obj.zOff;
            end
            obj.timeAcu2=obj.timeAcu2+obj.SampleTime;
        end
        if obj.curState==0 && obj.timeAcu0>=obj.tsk
            obj.curState=1;
            obj.timeAcu0=0;
        end
        if obj.curState==1
            if obj.ENFlag>0.5 && tdFlag>0.5
                obj.curState=2;
            end
        end
        if obj.curState==2
            if obj.timeAcu2>=obj.tdy+obj.tst+obj.tst_wt
                obj.curState=0;
                obj.timeAcu2=0;
            end
        end
        if obj.ENFlag<0.5
            isStill=1;
        else
            isStill=0;
        end
        end
        
        
        function flag = isInactivePropertyImpl(obj,prop)
            flag = false;
            switch char(obj.SampleTimeTypeProp)
                case {'Inherited', ...
                        'InheritedNotControllable', ...
                        'FixedInMinorStep'}
                    if any(strcmp(prop,{'SampleTime','OffsetTime','TickTime'}))
                        flag = true;
                    end
                case 'Discrete'
                    if any(strcmp(prop,{'TickTime'}))
                        flag = true;
                    end
                case 'Controllable'
                    if any(strcmp(prop,{'SampleTime','OffsetTime'}))
                        flag = true;
                    end
            end
        end
    end
%     methods (Static, Access=protected)
%         function header = getHeaderImpl
%             header=matlab.system.display.Header(mfilename('class'), ...
%                    'Title','Phase Oscillator',...
%                    'Text',['Counts Hits and Time.', ...
%                    ' When EN==false, StopIndFlag will firstly be triggered when the phase(1) crosses the stopIndPhase, ',...
%                    'then all phase will grow until phase(1) reaches the stopPhase. ', ...
%                    'Note that as long as phase(1) reaches the stopPhase, all phase will be reseted to their initial values']);
%         end
%     end
end