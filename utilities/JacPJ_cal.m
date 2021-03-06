function [Jac_pj,Jac_pDGm,Jac_pGHm,deltaPJ]=JacPJ_cal(theta2,theta3,encoderArry)
   AC=0.2;
   BE=0.13;
   DG=0.2;
   CD=0.07;
   FG=AC-BE; % will be updated in the setup function
   GH=0.2;
   CDG=3.2563;
   FGH=-3.1915;
   %[pH,BDG,DGH]=LegFK(AC,BE,CD,CDG,DG,FG,FGH,GH,theta2,theta3);
   [pH,CDGnow,FGHnow]=LegFK_v2(AC,BE,CD,encoderArry(1),DG,FG,encoderArry(2),GH,theta2,theta3);
   pH
   deltaPJ=[CDGnow-CDG;FGHnow-FGH]
%    CDGnow=CDG+encoderArry(1)-BDG;
%    FGHnow=FGH+encoderArry(2)-DGH;
   Jac_pj = LegJac_PJ_embedded(AC,BE,CDGnow,DG,FG,FGHnow,GH,theta2,theta3-pi/2);
   %Jac_pj = JacPJ_num(AC,BE,CD,CDGnow,DG,FG,FGHnow,GH,theta2,theta3);
   Jac_pDGm=LegJac_pDGm_embedded(CDGnow,DG,theta2,theta3-pi/2);
   Jac_pGHm=LegJac_pGHm_embedded(AC,BE,CDGnow,DG,FG,FGHnow,GH,theta2,theta3-pi/2);
end

% subfunction
function [pH,BDG,DGH]=LegFK(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)
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
end

function [pH,CDGnow,FGHnow]=LegFK_v2(AC,BE,CD,BDG,DG,FG,DGH,GH,theta1,theta2)
% BDG: angle from BD extension line to DG, normally positive
% DGH: angle from DG extension line to GH, normally negative
    theta2=theta2-pi/2;
    pB=[0;0];
    pD=Rz2D(theta1)*[0;-AC];
    pA=Rz2D(theta2)*CD/AC*(pD-pB)+pB;
    pC=pA+pD-pB;
    pE=Rz2D(theta1)*[0;-BE];
    pG=Rz2D(BDG)*DG/AC*(pD-pB)+pD;
    pF=pE+pG-pD;
    pH=Rz2D(DGH)*GH/DG*(pG-pD)+pG;
    CDGnow=real(acos((pD-pB)'*(pC-pD)/AC/CD)+ acos((pD-pB)'*(pG-pD)/AC/DG));
    FGHnow=real(-acos((pG-pD)'*(pF-pG)/DG/FG)-acos((pG-pD)'*(pH-pG)/DG/GH));
%     BDG=real(acos((pG-pD)'*(pD-pB)/AC/DG));
%     DGH=real(-acos((pH-pG)'*(pG-pD)/DG/GH));
end

function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end

function dpH_pj = LegJac_PJ_embedded(AC,BE,CDG,DG,FG,FGH,GH,theta1,theta2)
%LegJac_PJ
%    dpH_pj = LegJac_PJ(AC,BE,CDG,DG,FG,FGH,GH,THETA1,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    11-May-2022 16:41:43

t2 = FGH+theta1;
t3 = CDG+theta1+theta2;
t4 = -BE;
t5 = 1.0./FG;
t6 = AC+t4;
dpH_pj = reshape([DG.*cos(t3),DG.*sin(t3),-GH.*t5.*t6.*cos(t2),-GH.*t5.*t6.*sin(t2)],[2,2]);
end


function dpDGm = LegJac_pDGm_embedded(CDG,DG,theta1,theta2)
%LegJac_pDGm
%    dpDGm = LegJac_pDGm(CDG,DG,THETA1,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    22-May-2022 16:15:50

t2 = CDG+theta1+theta2;
dpDGm = reshape([(DG.*cos(t2))./2.0,(DG.*sin(t2))./2.0,0.0,0.0],[2,2]);
end

function dpGHm = LegJac_pGHm_embedded(AC,BE,CDG,DG,FG,FGH,GH,theta1,theta2)
%LegJac_pGHm
%    dpGHm = LegJac_pGHm(AC,BE,CDG,DG,FG,FGH,GH,THETA1,THETA2)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    22-May-2022 16:15:50

t2 = FGH+theta1;
t3 = CDG+theta1+theta2;
t4 = -BE;
t5 = 1.0./FG;
t6 = AC+t4;
dpGHm = reshape([DG.*cos(t3),DG.*sin(t3),GH.*t5.*t6.*cos(t2).*(-1.0./2.0),GH.*t5.*t6.*sin(t2).*(-1.0./2.0)],[2,2]);
end