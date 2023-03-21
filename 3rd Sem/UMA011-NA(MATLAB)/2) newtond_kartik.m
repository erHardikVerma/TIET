clc
clear all
x=[1,1.5,2,2.5];
y=[2.7183,4.4817,7.3891,12.1825];
n=length(x);
D=zeros(n,n);
p=2.25;
for i=1:n
    D(i,1)=y(i);
end
for i=2:n
    for j=2:i
        D(i,j)=(D(i,j-1)-D(i-1,j-1))/(x(i)-x(i-j+1));
    end
end
for i=1:n
    l(i)=1;
    for j=1:i-1
        l(i)=l(i)*(p-x(j));
    end
end
sum=0;
for i=1:n
    sum=sum+l(i)*D(i,i);
end
disp(sum);
