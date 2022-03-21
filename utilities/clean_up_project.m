function clean_up_project()
%clean_up_project   Clean up project
% 
%   Clean up the environment for the current project. This function undoes
%   the settings applied in "set_up_project". It is set to Run at Shutdown.

%   Copyright 2020 The MathWorks, Inc.

% Reset the location where generated code and other temporary files are
% created (slprj) to the default:
Simulink.fileGenControl('reset');
end

