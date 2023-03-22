clc;
clear all;
A=[1,1,0,0;1,2,0,1;0,0,3,3;0,1,2,3];
x0=[1;1;0;1];
tol=10^-6;
error1=inf;
while norm(error1,inf)>tol
    y=A*x0;
    k=norm(y,inf);
    x1=(1/k)*y;
    error1=x1-x0;
    x0=x1;
end
disp (x1);
disp(k);