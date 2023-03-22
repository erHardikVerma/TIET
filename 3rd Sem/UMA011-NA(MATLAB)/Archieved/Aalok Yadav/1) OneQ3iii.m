clc;
clear all;
f=@ (x) x^3+4*x^2-10;
tol=10^-3;
a=1;
b=2;
n=(log(b-a)-log(tol))/log(2);
disp (ceil(n))
while abs(f(a)*f(b))>tol
    x=(a+b)/2;
    if(f(a)*f(x)<0)
        b=x;
    else
        a=x;
    end
end
disp (x)