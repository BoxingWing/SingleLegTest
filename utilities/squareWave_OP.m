classdef squareWave_OP< matlab.System
    % open-loop one-period square wave generation

    properties
        tHigh=0.5;
        tLow=0.5
        Amp=10;
    end

    properties(Nontunable)
        SampleTime = 0.005; % Sample Time
        OffsetTime = 0; % Offset Time
        TickTime = 0;
        SampleTimeTypeProp (1, 1) {mustBeMember(SampleTimeTypeProp, ...
            ["Discrete","FixedInMinorStep","Controllable",...
            "Inherited","InheritedNotControllable",...
            "InheritedErrorConstant"])} = "Discrete"
    end

    properties(Access = private)
        AmpOff=0; % make this value 0 such that the motor can be calibrated at the start
        PhaseOld;
        ENOld=0;
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
            %obj.Count = 0;
            obj.ENOld=0;
        end

        function resetImpl(obj)
            % Initialize / reset discrete-state properties
            obj.PhaseOld=0;
        end

        function [Tra,isStill] = stepImpl(obj,ENNum)
            if obj.ENOld==0
                obj.ENOld=ENNum;
            end
            if obj.PhaseOld>=2*pi && obj.ENOld~=ENNum
                obj.ENOld=ENNum;
                obj.PhaseOld=0;
            end
            if obj.ENOld~=ENNum
                isStill=0;
            else
                isStill=1;
            end
            if obj.ENOld~=ENNum
                dPhi=2*pi/(obj.tHigh+obj.tLow)*obj.SampleTime;
                obj.PhaseOld=obj.PhaseOld+dPhi;
                if obj.PhaseOld>2*pi
                    obj.PhaseOld=2*pi;
                end
                if obj.PhaseOld<2*pi*obj.tHigh/(obj.tHigh+obj.tLow)
                    Tra=obj.Amp+obj.AmpOff;
                else
                    Tra=obj.AmpOff;
                end
            else
                Tra=obj.AmpOff;
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