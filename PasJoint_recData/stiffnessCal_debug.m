% check from the webots results
motor2=-0.47;
motor3=-0.2;
CDG_FB=3.26274;
FGH_FB=-3.19150;
[Jac_pj,deltaPJ_cur]=JacPJ_cal_webots(motor2,motor3,[BDG_FB;DGH_FB]);
tauPJ=Jac_pj'*(-1)*[2.0750;179.9368]
% stiffness(1,i)=tauPJ(1)/deltaPJ_cur(1);
% stiffness(2,i)=tauPJ(2)/deltaPJ_cur(2);