clc;
clear all;
A=[1/3,1/2,-1/4;1/5,2/3,3/8;2/3,-2/3,5/8];
b=[16;9;10];
y=[A,b];
[n,k]=size(y);
l=eye(n);
for i=1:n-1
    for j=(i+1):n
        m(j,i)=y(j,i)/y(i,i);
        y(j,:)=y(j,:)-(y(i,:)*y(j,i))/y(i,i);
    end
end
u=y(:,1:k-1);
b=y(:,k);
p=inv(l)*b;
x=inv(u)*p;
disp(x);