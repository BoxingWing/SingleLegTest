clear variables;close all;
fileName='20220510T170419.mat';
load(fileName);
%timeSeg=[21,24;44,48];
timeFava=[5,10];
% encoder clean
Encoder_FB_new=Encoder_FB;
for i=2:1:length(Encoder_FB_new(1,:))
    if abs(Encoder_FB_new(1,i)-Encoder_FB_new(1,i-1))>5/180*pi
        Encoder_FB_new(1,i)=Encoder_FB_new(1,i-1);
    end
    if abs(Encoder_FB_new(2,i)-Encoder_FB_new(2,i-1))>5/180*pi
        Encoder_FB_new(2,i)=Encoder_FB_new(2,i-1);
    end
end

figure()
subplot(2,1,1)
plot(time,Encoder_FB_new(1,:),time,Encoder_FB(1,:));
legend('cleaned','original')
subplot(2,1,2)
plot(time,Encoder_FB_new(2,:),time,Encoder_FB(2,:));
legend('cleaned','original')


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

% plot passive joint
figure();
subplot(2,1,1)
plot(time,Encoder_FB(1,:),time,Encoder_Des(1,:));
ylabel('Encoder1');xlabel('time')
legend('FB','Des')
subplot(2,1,2)
plot(time,Encoder_FB(2,:),time,Encoder_Des(2,:));
ylabel('Encoder1');xlabel('time')
legend('FB','Des');

% plot contact force
figure()
plot(time,fxyz(1,:),time,fxyz(2,:),time,fxyz(3,:));
ylabel('f');legend('fx','fy','fz')

answer=questdlg('Append the cleaned encoder data and the timeSeg variable?','save quest','yes','no','no');
if strcmp(answer,'yes')
    save(fileName,'timeSeg','Encoder_FB_new','timeFava','-append');
end

