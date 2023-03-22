clc;
clear all;
syms x;
f=@ (x) (sqrt(1+(cos(x))^2));
a=1;
b=2;
n=10;
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