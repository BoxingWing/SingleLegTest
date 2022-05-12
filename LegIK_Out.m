function [theta1,theta2]=LegIK_Out(AC,BE,CD,CDG,DG,FG,FGH,GH,pH)
% hardware offsets are removed
pH=reshape(pH,2,1);
pB=[0;0];
TG=BE+FG;
TH=sqrt(TG^2+GH^2-2*TG*GH*cos(2*pi+FGH));
TB=DG;
if FGH<=-pi
    HTG=asin(GH*abs(sin(FGH))/TH);
else
    HTG=-asin(GH*abs(sin(FGH))/TH);
end
[tmpx,tmpy]=Get1From2(pB(1),pB(2),pH(1),pH(2),TB,TH,'xBigger');
pT=[tmpx;tmpy];
pF=Rz2D(HTG)*BE/TH*(pH-pT)+pT;
pG=Rz2D(HTG)*TG/TH*(pH-pT)+pT;
pE=pF+pB-pT;
pD=pG+pB-pT;
pC=Rz2D(-CDG)*CD/DG*(pG-pD)+pD;
pA=pB+pC-pD;

%theta1=sign(pE(1))*atan(abs(pE(1)/pE(2)));
theta1=sign(pD(1))*acos(pD'*[0;-1]/AC);
theta2=-acos((pA-pB)'*(pC-pA)/CD/AC)+pi/2; % here is different from the opt program

% if pF(1)<=pB(1) && pF(2)>=pB(2) % sigular pose
%     theta1=complex(0,1);
%     theta2=complex(0,1);
% end
end

function [xout,yout]=Get1From2(x1,y1,x2,y2,l1,l2,limit)
% get a point position with its distances to two ref points
% this function will return 99 if no solution found
% limit: yBigger, ySmaller, xBigger, xSmaller

D=sqrt((x1-x2)^2+(y1-y2)^2);
if ~(l1+l2>=D && abs(l1-l2)<D)
    xout=complex(0,1);
    yout=complex(0,1);
    return;
end
% if abs(l1+l2-D)<10^-3
%     xout=x1+l1/D*(x2-x1);
%     yout=y1+l1/D*(y2-y1);
%     return;
% end
A=(l1+l2)^2-(x1-x2)^2-(y1-y2)^2;
B=-(l1-l2)^2+(x1-x2)^2+(y1-y2)^2;
E=(-l1^2+l2^2)*(y1-y2)+(y1+y2)*((x1-x2)^2-y1*y2)+y1^3+y2^3;
F=2*((x1-x2)^2+(y1-y2)^2);
temp=sqrt(A*B);
yo1=(x1*temp-x2*temp+E)/F;
yo2=(x2*temp-x1*temp+E)/F;
xo1=sqrt(l1^2-(yo1-y1)^2)+x1;
if abs((xo1-x2)^2+(yo1-y2)^2-l2^2)>10^-4
    xo1=-sqrt(l1^2-(yo1-y1)^2)+x1;
end
xo2=sqrt(l1^2-(yo2-y1)^2)+x1;
if abs((xo2-x2)^2+(yo2-y2)^2-l2^2)>10^-4
    xo2=-sqrt(l1^2-(yo2-y1)^2)+x1;
end
if abs(yo1-yo2)<10^-4
    xo2=2*x1-xo1;
end
if strcmp('yBigger',limit)
    if yo1>yo2
        yout=yo1;
        xout=xo1;
    else
        yout=yo2;
        xout=xo2;
    end
elseif strcmp('ySmaller',limit)
    if yo1<yo2
        yout=yo1;
        xout=xo1;
    else
        yout=yo2;
        xout=xo2;
    end
elseif strcmp('xSmaller',limit)
    if xo1<xo2
        yout=yo1;
        xout=xo1;
    else
        yout=yo2;
        xout=xo2;
    end
elseif strcmp('xBigger',limit)
    if xo1>xo2
        yout=yo1;
        xout=xo1;
    else
        yout=yo2;
        xout=xo2;
    end
else
    error('wrong input option!');
end
end

function M=Rz2D(theta)
% 2D rotation function
M=[cos(theta),-sin(theta);
    sin(theta),cos(theta)];
end