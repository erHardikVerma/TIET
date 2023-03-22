clc;
clear all;
A=[4,1,-1,1;1,4,-1,-1;-1,-1,5,1;1,-1,1,3];
b=[-2;-1;0;1];
n=size(A,1);
tol=10^-3;
x0=[0;0;0;0];
err=[inf,inf,inf];
while norm(err,inf)>tol
    for i=1:n
        sum=0;
        for j=1:n
            if j~=i
                sum=sum+A(i,j)*x0(j);
            end
        end
        x(i)=(b(i)-sum)/A(i,i);
        err(i)=x(i)-x0(i);
        x0(i)=x(i);
    end
end
disp (x0);
