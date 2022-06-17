function dpGHm = LegJac_pGHm(AC,BE,CDG,DG,FG,FGH,GH,theta1,theta2)
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
