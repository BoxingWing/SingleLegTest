% check from the webots results
motor2=-0.47;
motor3=-0.17;
CDG_FB=3.25943;
FGH_FB=-3.19763;
fx=0.10374;
fz=63.18785;
tau2=-2.093;
tau3=-12.06215;


[Jac_pj,Jac_aj,Jcp,deltaPJ_cur]=JacPJ_cal_webots(motor2,motor3,[CDG_FB;FGH_FB]);
tauPJ=Jac_pj'*(-1)*[fx;fz]-Jcp'*[tau2;tau3]
stiffness1=tauPJ(1)/deltaPJ_cur(1)
stiffness2=tauPJ(2)/deltaPJ_cur(2)


% stiffness(1,i)=tauPJ(1)/deltaPJ_cur(1);
% stiffness(2,i)=tauPJ(2)/deltaPJ_cur(2);
