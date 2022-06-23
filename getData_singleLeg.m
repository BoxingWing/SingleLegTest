%% fetch data from raspberry pi
mypi=raspberrypi;
getFile(mypi,'sl_dataRec*.mat');
getFile(mypi,'~/MATLAB_ws/R2021b/IK_sgl_Test.log'); % get the log file

%% data plot
close all;
load sl_dataRec1.mat;
load sl_dataRec2.mat;
load sl_dataRec3.mat;
time=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(1,:);
MotorAngle_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(2:4,:);
MotorCab=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(5:7,:);
Encoder_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(8:9,:);
MotorSpeed_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(10:12,:);
MotorCurrent_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(13:15,:);
fe_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(16:17,:);
td_FB=MotorAngle_cab_Encoder_motorSpeed_motorCurrent_fe_td(18,:);
pH_Des=pEnd_AngleSegDeg_pHFB_FKPJ(2:3,:);
MotorAngle_Des=pEnd_AngleSegDeg_pHFB_FKPJ(4:6,:);
pH_FB=pEnd_AngleSegDeg_pHFB_FKPJ(7:8,:);
Encoder_Des=pEnd_AngleSegDeg_pHFB_FKPJ(9:10,:);
fxyz=fx_fy_fz_mx_my_mz_size(2:4,:);
Mxyz=fx_fy_fz_mx_my_mz_size(5:7,:);
udpSize=fx_fy_fz_mx_my_mz_size(8,:);

% plot foot end
figure()
subplot(2,1,1)
plot(time,pH_FB(1,:),time,pH_Des(1,:));
ylabel('pHx');xlabel('time');
legend('FB','Des');
subplot(2,1,2)
plot(time,pH_FB(2,:),time,pH_Des(2,:));
ylabel('pHy');xlabel('time');
legend('FB','Des');

% plot foot end force
figure()
plot(time,fe_FB(1,:),time,fe_FB(2,:));
ylabel('fe');xlabel('time');
legend('fx','fz');

% plot motor angle
figure()
subplot(3,1,1)
plot(time,MotorAngle_FB(1,:),time,MotorAngle_Des(1,:));
ylabel('motorAngle1');xlabel('time');
legend('FB','Des');
subplot(3,1,2)
plot(time,MotorAngle_FB(2,:),time,MotorAngle_Des(2,:));
ylabel('motorAngle2');xlabel('time');
legend('FB','Des');
subplot(3,1,3)
plot(time,MotorAngle_FB(3,:),time,MotorAngle_Des(3,:));
ylabel('motorAngle3');xlabel('time');
legend('FB','Des');

% plot motor speed
figure()
subplot(3,1,1)
plot(time,MotorSpeed_FB(1,:));
ylabel('motorSpeed1');xlabel('time');
subplot(3,1,2)
plot(time,MotorSpeed_FB(2,:));
ylabel('motorSpeed2');xlabel('time');
subplot(3,1,3)
plot(time,MotorSpeed_FB(3,:));
ylabel('motorSpeed3');xlabel('time');

% plot motor current
figure()
subplot(3,1,1)
plot(time,MotorCurrent_FB(1,:));
ylabel('motorCurrent1');xlabel('time');
subplot(3,1,2)
plot(time,MotorCurrent_FB(2,:));
ylabel('motorCurrent2');xlabel('time');
subplot(3,1,3)
plot(time,MotorCurrent_FB(3,:));
ylabel('motorCurrent3');xlabel('time');


% plot passive joint
figure();
subplot(2,1,1)
plot(time,Encoder_FB(1,:),time,Encoder_Des(1,:));
ylabel('Encoder1');xlabel('time');legend('FB','Des')
subplot(2,1,2)
plot(time,Encoder_FB(2,:),time,Encoder_Des(2,:));
ylabel('Encoder2');xlabel('time');legend('FB','Des')

% plot contact force
figure()
plot(time,fxyz(1,:),time,fxyz(2,:),time,fxyz(3,:));
ylabel('f');legend('fx','fy','fz')


answer=questdlg('save the current data to a new file?','save quest','yes','no','no');
if strcmp(answer,'yes')
dateNow=datestr(now,30);
fileName=[dateNow,'.mat'];
save(fileName,'time','MotorAngle_Des','MotorAngle_FB','MotorCab',...
    'Encoder_Des','Encoder_FB','pH_FB','pH_Des','fxyz','Mxyz','udpSize');
end








