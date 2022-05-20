% check from the webots results
motor2=-0.49064;
motor3=-0.2;
CDG_FB=3.25260;
FGH_FB=-3.20749;
fx=0;
fz=112.2131;

[Jac_pj,deltaPJ_cur]=JacPJ_cal_webots(motor2,motor3,[CDG_FB;FGH_FB]);
tauPJ=Jac_pj'*(-1)*[fx;fz]
stiffness1=tauPJ(1)/deltaPJ_cur(1)
stiffness2=tauPJ(2)/deltaPJ_cur(2)


% stiffness(1,i)=tauPJ(1)/deltaPJ_cur(1);
% stiffness(2,i)=tauPJ(2)/deltaPJ_cur(2);
