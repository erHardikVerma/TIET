clc;
clear all;
x=[0,0.25,0.5,0.75];
y=[1,1.64872,2.71828,4.48169];
n=length(x);
p=0.43;
l=eye(n);
for i=1:n
    l(i)=1;
    for j=1:n
        if j~=i
            l(i)=l(i)*((p-x(j))/(x(i)-x(j)));
        end
    end
end
sum=0;
for i=1:n
    sum=sum+(l(i)*y(i));
end
disp (sum);
