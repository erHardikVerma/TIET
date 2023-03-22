clc;
clear all;
x = [0,0.25,0.5,0.75];
y = [1,1.64872,2.71828,4.4816];
n=length(x);
p=0.43;
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