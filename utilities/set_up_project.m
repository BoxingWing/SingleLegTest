function set_up_project()
%set_up_project  Configure the project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

%   Copyright 2020 The MathWorks, Inc.

% Use Simulink Project API to get the current project:
project = simulinkproject;

architectureXML = ...
['<architecture brief="Multicore with core affinity" format="1.1"  revision="1.1" uuid="MulticoreCustomAPI"  name="MulticoreCustomAPI">',newline,...
'<configurationSet>',newline,...
'<parameter name="SystemTargetFile" value="ert.tlc"/>',newline,...
'</configurationSet>',newline,...
'<node name="MulticoreProcessor" type="SoftwareNode" uuid="MulticoreProcessor"/>',newline,...
'<template name="CustomTask" type="Task" uuid="CustomTask">',newline,...
'<property name="TaskAffinity" prompt="Affinity:" value="1" evaluate="true"/>',newline,...
'</template>',newline,...
'</architecture>'];

% Make sure Simulink is loaded with the custom architecture
projectRoot = project.RootFolder;
architectureXMLfile = fullfile(projectRoot,'architecture','CustomArchitecture.xml');
if ~isfile(architectureXMLfile)
    % Create architecture xml
    fileId = fopen(architectureXMLfile,'w');
    fprintf(fileId,'%s',architectureXML);
    fclose(fileId);
end
Simulink.architecture.register(architectureXMLfile);
end
