% BISECTION'S METHOD

clc
clear all

a = 1;
b = 10;
tol = 0.001;
x = 0:10;
f = @(x) x.^2-4.*x-2;
if(f(a)*f(b)>0)
disp('wrong a and b value)
else
while abs(f(c))>tol
    if f(a)*f(c)<0
        b=c;
    else
        a=c;
    end
    c=(a+b)/2;
end
end

fprintf('Root = %f',c)
