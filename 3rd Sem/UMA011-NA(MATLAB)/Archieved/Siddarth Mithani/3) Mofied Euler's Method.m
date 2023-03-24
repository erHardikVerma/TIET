%Modified Eulers Method
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
    y(i+1)=y(i)+h*f(x(i),y(i));
    y(i+1)=y(i)+(h/2)*(f(x(i+1),y(i+1)));
end
y
%plot(x,y)
