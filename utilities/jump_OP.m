classdef jump_OP< matlab.System
    % open-loop jump trajectory generation
    
    properties
        tUp=0.3;
        tDown=0.15;
        Amp=0;
        AmpOff=-0.5;
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
        
        function [zTra,isStill] = stepImpl(obj,ENNum)
            if obj.ENOld==0
                obj.ENOld=ENNum;
            end
            if obj.PhaseOld>=pi && obj.ENOld~=ENNum
                obj.ENOld=ENNum;
                obj.PhaseOld=0;
            end
            if obj.ENOld~=ENNum
                isStill=0;
            else
                isStill=1;
            end
            if obj.ENOld~=ENNum
               k1=pi/2/obj.tUp;
               k2=pi/2/obj.tDown;
               dPhi=0;
               if obj.PhaseOld<pi/2
                   dPhi=k1*obj.SampleTime;
               else
                   dPhi=k2*obj.SampleTime;
               end
               obj.PhaseOld=obj.PhaseOld+dPhi;
               if obj.PhaseOld>pi
                   obj.PhaseOld=pi;
               end
               zTra=obj.Amp*sin(obj.PhaseOld)+obj.AmpOff;
            else
               zTra=obj.AmpOff;
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