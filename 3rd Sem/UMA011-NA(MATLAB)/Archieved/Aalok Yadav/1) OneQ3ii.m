clc;
clear all;
f=@ (x) (1/2)+sin(x)-cos(x);
tol=0.001;
count=0;
for i=0:100
    if(f(i)*f(i+1)<0)
        a=i;
        b=i+1;
        break
    end
end
while abs(f(a)*f(b))>tol
    x=(a+b)/2;
    count=count+1;
    if(f(a)*f(x)<0)
        b=x;
    else
        a=x;
    end
end
disp (x)
disp (count)