%RK
clc
clear all
f=@(x,y) -y+2*cos(x);
a=0;
b=1;
x(1)=0;
y(1)=1;
h=0.2;
n=(b-a)/h;
for i=1:n
    x(i+1)=x(i)+h;
    k1=h*f(x(i),y(i));
    k2=h*f(x(i)+h/2,y(i)+k1/2);
    k3=h*f(x(i)+h/2,y(i)+k2/2);
    k4=h*f(x(i)+h,y(i)+k3);
    y(i+1)=y(i)+(k1+(k3+k2)*2+k4)/6;
end
y
