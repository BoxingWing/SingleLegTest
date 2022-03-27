classdef canSendRecv < matlab.System & ...
        coder.ExternalDependency ...
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon
    %
    % System object template for a source block.
    % 
    % This template includes most, but not all, possible properties,
    % attributes, and methods that you can implement for a System object in
    % Simulink.
    %
    % NOTE: When renaming the class name Source, the file name and
    % constructor name must be updated to use the class name.
    %
    
    % Copyright 2016-2018 The MathWorks, Inc.
    %#codegen
    %#ok<*EMCA>
    
    properties
        canPort='can1';
    end
    
    properties (Nontunable)
        % Public, non-tunable properties.
    end
    
    properties (Access = private)
        % Pre-computed constants.
    end
    
    methods
        % Constructor
        function obj = canSendRecv(varargin)
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end
    
    methods (Access=protected)
        function setupImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation setup code here
            else
                % Call C-function implementing device initialization
                obj.canPort='can1';
                coder.cinclude('can_motor_encoder.h');
                coder.ceval('canSetup',obj.canPort);
            end
        end
        
        function [recv_ID,recv_rawData,err] = stepImpl(obj,canID_array,send_RawData,dev_Num)   %#ok<MANU>
            % canID_array: int32 *
            % send_RawData: uint8 *
            % dev_Num: unint8
            recv_ID = int32(zeros(4,1)); % up to 4 devices
            recv_rawData=uint8(zeros(32,1)); 
            err=int32(0);
            if isempty(coder.target)
                % Place simulation output code here
            else
                % Call C-function implementing device output
                %y = coder.ceval('source_output');
                err=coder.ceval('batchMessage', canID_array, send_RawData, dev_Num, coder.ref(recv_ID), coder.ref(recv_rawData));
            end
        end
        
        function releaseImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation termination code here
            else
                % Call C-function implementing device termination
                coder.ceval('close_port');
            end
        end
    end
    
    methods (Access=protected)
        %% Define output properties
        function num = getNumInputsImpl(~)
            num = 3;
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
            varargout{1} = [4,1];
            varargout{1} = [32,1];
            varargout{1} = [1,1];
        end
        
        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'int32';
            varargout{2} = 'uint8';
            varargout{3} = 'int32';
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'CAN_Driver';
        end    
    end
    
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    
    methods (Static)
        function name = getDescriptiveName()
            name = 'CAN_Driver';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src'); %#ok<NASGU>
                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);
                % Use the following API's to add include files, sources and
                % linker flags
                addIncludeFiles(buildInfo,'can_motor_encoder.h',includeDir);
                addSourceFiles(buildInfo,'can_motor_encoder.c',srcDir);
                %addLinkFlags(buildInfo,{'-lSource'});
                %addLinkObjects(buildInfo,'sourcelib.a',srcDir);
                %addCompileFlags(buildInfo,{'-D_DEBUG=1'});
                %addDefines(buildInfo,'MY_DEFINE_1')
            end
        end
    end
end
