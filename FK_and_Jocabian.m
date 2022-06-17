clear variables; close all;
syms theta1 theta2 real;
syms AC BE DG CD FG GH positive;
syms CDG FGH BDG DGH real;
pB=[0;0];
FG=AC-BE;
pD=Rz2D(theta1)*[0;-AC];
pA=Rz2D(theta2)*CD/AC*(pD-pB)+pB;
pC=pA+pD-pB;
pE=Rz2D(theta1)*[0;-BE];
pG=Rz2D(CDG)*DG/CD*(pC-pD)+pD;
pF=pE+pG-pD;
pH=Rz2D(FGH)*GH/FG*(pF-pG)+pG;
pDGm=0.5*(pD+pG);
pGHm=0.5*(pG+pH);
dpH=simplify(jacobian(pH,[theta1,theta2]))
dpH_pj=simplify(jacobian(pH,[CDG,FGH]))
% dpDGm=simplify(jacobian(pDGm,[CDG,FGH]))
% dpGHm=simplify(jacobian(pGHm,[CDG,FGH]))
dpH_AllFour=simplify(jacobian(pH,[theta1,theta2,CDG,FGH]));
Jac=dpH_AllFour(1:2,1:2);
Jpj=dpH_AllFour(1:2,3:4);
Jcp=simplify(Jac\Jpj);

%matlabFunction(Jcp,'File','LegJac_Jcp');

% matlabFunction(dpH_pj,'File','LegJac_PJ');
% matlabFunction(dpDGm,'File','LegJac_pDGm');
% matlabFunction(dpGHm,'File','LegJac_pGHm');

% matlabFunction(pH,'File','LegFK');
% matlabFunction(dpH,'File','LegJac');
% matlabFunction(pH,pA,pC,pD,pE,pF,pG,'File','LegFK_ex');

% pB=[0;0];
% pD=Rz2D(theta1)*[0;-AC];
% pA=Rz2D(theta2)*CD/AC*(pD-pB)+pB;
% pC=pA+pD-pB;
% pE=Rz2D(theta1)*[0;-BE];
% pG=Rz2D(BDG)*DG/AC*(pD-pB)+pD;
% pF=pE+pG-pD;
% pH=Rz2D(DGH)*GH/DG*(pG-pD)+pG;
% %dpH=simplify(jacobian(pH,[theta1,theta2]));
% dpH_pj2=simplify(jacobian(pH,[BDG,DGH]));
% 
% matlabFunction(dpH_pj2,'File','LegJac_PJ');

%% subfunction
function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end



