clc;
clear all;
A=[10,8,-3,1;2,10,1,-4;3,-4,10,1;2,2,-3,10];
b=[16;9;10;11];
n=size(A,1)
y=[A,b];
for i=1:n-1
    for j=i+1:n
        y(j,:)=y(j,:)-(y(i,:)*y(j,i))/y(i,i);
    end
end
disp (y)
x=zeros(n,1);
x(n)=y(n,n+1)/y(n,n);
for i=n-1:-1:1
    sum=0;
    for j=i+1:n
    sum=sum+(y(i,j)*x(j));
    end
    x(i)=(y(i,n+1)-sum)/y(i,i);
end
disp (x)
