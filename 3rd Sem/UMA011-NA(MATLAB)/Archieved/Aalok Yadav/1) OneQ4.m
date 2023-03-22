clc;
clear all;
x0=1.5;
f=@ (x) x^3+4*x^2-10;
g1=@ (x1) x1-x1^3-4*(x1^2)+10;
g2=@ (x2) sqrt((10/x2)-4^x2);
g3=@ (x3) 0.5*sqrt(10-x3^3);
g4=@ (x4) sqrt(10/(4+x4));
g5=@ (x5) x5-((x5^3+4*(x5^2)-10)/(3*x5^2+8*x5));
syms x1;
h1=diff(g1,x1);
syms x2;
h2=diff(g2,x2);
syms x3;
h3=diff(g3,x3);
syms x4;
h4=diff(g4,x4);
syms x5;
h5=diff(g5,x5);
i1=abs(vpa(subs(h1,x0)));
i2=abs(vpa(subs(h2,x0)));
i3=abs(vpa(subs(h3,x0)));
i4=abs(vpa(subs(h4,x0)));
i5=abs(vpa(subs(h5,x0)));
if((i1<i2)&&(i1<i3)&&(i1<i4)&&(i1<i5))
    disp (g1)
elseif((i2<i1)&&(i2<i3)&&(i2<i4)&&(i2<i5))
    disp (g2)
elseif((i3<i1)&&(i3<i2)&&(i3<i4)&&(i3<i5))
    disp (g3)
elseif((i4<i1)&&(i4<i3)&&(i4<i3)&&(i4<15))
    disp (g4)
else
    disp (g5)
end

