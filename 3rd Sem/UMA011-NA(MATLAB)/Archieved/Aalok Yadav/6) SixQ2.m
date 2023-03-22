clc;
clear all;
A=[4,1,0;1,20,1;0,1,4];
x=[1;1;1];
x0=[1;1;1];
tol=10^-6;
error1=inf;
error2=inf;
B=inv(A);
while norm(error1,inf)>tol
    y=A*x0;
    k=norm(y,inf);
    x1=(1/k)*y;
    error1=x1-x0;
    x0=x1;
end
while norm(error2,inf)>tol
    z=B*x;
    l=norm(z,inf);
    x2=(1/l)*z;
    error2=x2-x;
    x=x2;
end

disp (x1);
disp(k);
disp(1/l);
disp(x);