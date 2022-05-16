clear variables;
close all;
fileName='20220510T170419.mat';
load(fileName);
Ntest=length(timeSeg(:,1));
stiffness=zeros(2,Ntest);
fEnd_ava=zeros(3,Ntest);
motor_ag_ava=zeros(3,Ntest);
encoder_ava=zeros(2,Ntest);
encoder_des_ava=zeros(2,Ntest);
deltaPJ_ava=zeros(2,Ntest);

tStart=timeFava(1);
tEnd=timeFava(2);
tmp=find(time>tStart);
nStart=tmp(1);
tmp=find(time>tEnd);
nEnd=tmp(1);
fOff=sum(fxyz(:,nStart:nEnd),2)/(nEnd-nStart+1);

for i=1:1:Ntest
    tStart=timeSeg(i,1);
    tEnd=timeSeg(i,2);
    tmp=find(time>tStart);
    nStart=tmp(1);
    tmp=find(time>tEnd);
    nEnd=tmp(1);
    fEnd_ava(:,i)=sum(fxyz(:,nStart:nEnd),2)/(nEnd-nStart+1);
    motor_ag_ava(:,i)=sum(MotorAngle_FB(:,nStart:nEnd),2)/(nEnd-nStart+1)*(-1)/180*pi;
    encoder_ava(:,i)=sum(Encoder_FB_new(:,nStart:nEnd),2)/(nEnd-nStart+1);
    encoder_des_ava(:,i)=sum(Encoder_Des(:,nStart:nEnd),2)/(nEnd-nStart+1);
    [Jac_pj,deltaPJ_cur]=JacPJ_cal(motor_ag_ava(2,i),motor_ag_ava(3,i),encoder_ava(:,i));
    tauPJ=Jac_pj'*(-1)*[-(fEnd_ava(1)-fOff(1));(fEnd_ava(3)-fOff(3))]; % negetive fx or not???
    stiffness(1,i)=tauPJ(1)/deltaPJ_cur(1);
    stiffness(2,i)=tauPJ(2)/deltaPJ_cur(2);
    deltaPJ_ava(:,i)=deltaPJ_cur;
end

stiffness

% % plot encoder
% figure();
% subplot(2,1,1)
% plot(time,Encoder_FB_new(1,:),time,Encoder_Des(1,:));
% xlabel('time');ylabel('encoder1');legend('FB','Des')
% subplot(2,1,2)
% plot(time,Encoder_FB_new(2,:),time,Encoder_Des(2,:));
% xlabel('time');ylabel('encoder2');legend('FB','Des')
%
% % plot motor
% figure()
% subplot(3,1,1)
% plot(time,MotorAngle_FB(1,:),time,MotorAngle_Des(1,:));
% ylabel('motor1');legend('FB','Des');
% subplot(3,1,2)
% plot(time,MotorAngle_FB(2,:),time,MotorAngle_Des(2,:));
% ylabel('motor2');legend('FB','Des');
% subplot(3,1,3)
% plot(time,MotorAngle_FB(3,:),time,MotorAngle_Des(3,:));
% ylabel('motor3');legend('FB','Des');
%
%
% % plot pH
% figure()
% subplot(2,1,1)
% plot(time,pH_FB(1,:),time,pH_Des(1,:));
% legend('FB','Des');
% subplot(2,1,2)
% plot(time,pH_FB(2,:),time,pH_Des(2,:));
% legend('FB','Des');














