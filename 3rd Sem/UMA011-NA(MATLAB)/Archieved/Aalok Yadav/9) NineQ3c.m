%Simpson's Rule
clc;
clear all;
syms x;
f=@ (x) (exp(-x^2)*cos(x));;
a=-1;
b=1;
n=20;
h=(b-a)/n;
sum=0;
for i=1:n-1
    x=a+(i*h);
    if rem(i,2)==0
        sum=sum+2*f(x);
    else
        sum=sum+(4*f(x));
    end
end
sum=(h/3)*(f(a)+f(b)+sum);
disp (sum);

%Trapezoidal Rule
sum1=0;
for i=1:n-1
    y=a+(i*h);
    sum1=sum1+(2*f(y));
end
sum1=(h/2)*(sum1+f(a)+f(b));
disp (sum1);
