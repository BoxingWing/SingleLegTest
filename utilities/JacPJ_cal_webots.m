function [Jac_pj,Jac_aj,Jcp,deltaPJ,pAll]=JacPJ_cal_webots(theta2,theta3,encoderArry)
AC=0.2;
BE=0.13;
DG=0.2;
CD=0.07;
FG=AC-BE; % will be updated in the setup function
GH=0.2;
CDG=pi;%3.2563;
FGH=-pi;%-3.1915;
CDGnow=encoderArry(1);
FGHnow=encoderArry(2);

[pAll,BDG,DGH]=LegFK_embedded(AC,BE,CD,CDGnow,DG,FG,FGHnow,GH,theta2,theta3);

deltaPJ=[encoderArry(1)-CDG;encoderArry(2)-FGH];

Jac_aj=zeros(2,2);
Jac_pj = LegJac_PJ_embedded(CDGnow,DG,FGHnow,GH,theta2,theta3-pi/2)

Jcp = LegJac_Jcp_embedded(AC,BE,CDGnow,DG,FG,FGHnow,GH,theta3-pi/2);


delta=10^-8;
% [pH,~,~]=LegFK(AC,BE,CD,CDGnow,DG,FG,FGHnow,GH,theta2,theta3);
% [pH1,~,~]=LegFK(AC,BE,CD,CDGnow+delta,DG,FG,FGHnow,GH,theta2,theta3);
% [pH2,~,~]=LegFK(AC,BE,CD,CDGnow,DG,FG,FGHnow+delta,GH,theta2,theta3);
% Jcol1=(pH1-pH)/delta;
% Jcol2=(pH2-pH)/delta;
% Jac_pj=[Jcol1,Jcol2];
% 
[pAll1,~,~]=LegFK_embedded(AC,BE,CD,CDGnow,DG,FG,FGHnow,GH,theta2+delta,theta3);
[pAll2,~,~]=LegFK_embedded(AC,BE,CD,CDGnow,DG,FG,FGHnow,GH,theta2,theta3+delta);
Jcol1=(pAll1.pH-pAll.pH)/delta;
Jcol2=(pAll2.pH-pAll.pH)/delta;
Jac_aj=[Jcol1,Jcol2];
end

% subfunction
function [pAll,BDG,DGH]=LegFK_embedded(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)
% BDG: angle from BD extension line to DG, normally positive
% DGH: angle from DG extension line to GH, normally negative
theta2=theta2-pi/2;
pB=[0;0];
pD=Rz2D(theta1)*[0;-AC];
pA=Rz2D(theta2)*CD/AC*(pD-pB)+pB;
pC=pA+pD-pB;
pE=Rz2D(theta1)*[0;-BE];
pG=Rz2D(CDG)*DG/CD*(pC-pD)+pD;
pF=pE+pG-pD;
pH=Rz2D(FGH)*GH/FG*(pF-pG)+pG;
BDG=real(acos((pG-pD)'*(pD-pB)/AC/DG));
DGH=real(-acos((pH-pG)'*(pG-pD)/DG/GH));
pAll.pD=pD;
pAll.pA=pA;
pAll.pC=pC;
pAll.pE=pE;
pAll.pF=pF;
pAll.pG=pG;
pAll.pH=pH;
end

function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end


function dpH_pj = LegJac_PJ_embedded(CDG,DG,FGH,GH,theta1,theta2)
%LegJac_PJ
%    dpH_pj = LegJac_PJ(CDG,DG,FGH,GH,THETA1,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    23-May-2022 18:15:09

t2 = FGH+theta1;
t3 = CDG+theta1+theta2;
dpH_pj = reshape([DG.*cos(t3),DG.*sin(t3),-GH.*cos(t2),-GH.*sin(t2)],[2,2]);
end

function Jcp = LegJac_Jcp_embedded(AC,BE,CDG,DG,FG,FGH,GH,theta2)
%LegJac_Jcp
%    Jcp = LegJac_Jcp(AC,BE,CDG,DG,FG,FGH,GH,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    23-May-2022 17:21:17

t2 = CDG+theta2;
t4 = -BE;
t5 = -FGH;
t3 = sin(t2);
t6 = AC+t4;
t7 = t2+t5;
t8 = sin(t7);
Jcp = reshape([0.0,1.0,-(GH.*t6.*t8)./(AC.*FG.*t3-AC.*GH.*t8+BE.*GH.*t8),(GH.*t6.*(DG.*t8-AC.*sin(FGH)))./(AC.*DG.*FG.*t3-AC.*DG.*GH.*t8+BE.*DG.*GH.*t8)],[2,2]);
end