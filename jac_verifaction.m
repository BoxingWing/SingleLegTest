clear variables;
close all;
AC=0.2;
BE=0.13;
DG=0.2;
CD=0.07;
FG=AC-BE; % will be updated in the setup function
GH=0.2;
CDG=3.2563;
FGH=-3.1915;

pH=[0,-0.5];
[theta1,theta2]=LegIK_Out(AC,BE,CD,CDG,DG,FG,FGH,GH,pH);
CDG = 3.2563+5/180*pi;
FGH = -3.1915;%-5/180*pi;

jacCal = LegJac_PJ(AC,BE,CDG,DG,FG,FGH,GH,theta1,theta2-pi/2)

jacNum = JacPJ_num(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)