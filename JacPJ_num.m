function Jac_pj=JacPJ_num(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2)
delta=10^-5;
[pH,~,~]=LegFK_Out(AC,BE,CD,CDG,DG,FG,FGH,GH,theta1,theta2);
[pH1,~,~]=LegFK_Out(AC,BE,CD,CDG+delta,DG,FG,FGH,GH,theta1,theta2);
[pH2,~,~]=LegFK_Out(AC,BE,CD,CDG,DG,FG,FGH+delta,GH,theta1,theta2);
Jcol1=(pH1-pH)/delta;
Jcol2=(pH2-pH)/delta;
Jac_pj=[Jcol1,Jcol2];