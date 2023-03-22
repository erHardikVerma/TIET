clc;
clear all;
x = [1.2,1.6,2.4,3.6,5.0];
y = [1.32,2.53,5.28,8.34,12.83];
n=length(x);
p=2.25;
D=zeros(n,n);
for i=1:n
    D(i,1) = y(i);
end
for i=2:n
   for j=2:i
       D(i,j)=(D(i,j-1)-D(i-1,j-1))/(x(i)-x(i-j+1));
    end
end
for i=1:n
    prod(i)=1;
    for j=1:i-1
        prod(i)=prod(i)*(p-x(j));
    end
end
sum=0;
for i=1:n
    sum=sum+prod(i)*D(i,i);
end
disp(sum);