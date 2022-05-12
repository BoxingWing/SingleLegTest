function [pH,BDG,DGH]=LegFK_Out(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)
% theta1 and theta2 are hardware inputs including the hardware offsets

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

function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end