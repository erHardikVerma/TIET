clc;
clear all;
x=[1950,1960,1970,1980,1990,2000];
y=[151326,179323,203302,226542,249633,281422];
n=length(x);
p1=1965;
p2=1975;
p3=1995;
l1=eye(n);
l2=eye(n);
l3=eye(n);
for i=1:n
    l1(i)=1;
    l2(i)=1;
    l3(i)=1;
    for j=1:n
        if j~=i
            l1(i)=l1(i)*((p1-x(j))/(x(i)-x(j)));
            l2(i)=l2(i)*((p2-x(j))/(x(i)-x(j)));
            l3(i)=l3(i)*((p3-x(j))/(x(i)-x(j)));
        end
    end
end
sum1=0;
sum2=0;
sum3=0;
for i=1:n
    sum1=sum1+(l1(i)*y(i));
    sum2=sum2+(l2(i)*y(i));
    sum3=sum3+(l3(i)*y(i));
end
disp (sum1);
disp (sum2);
disp (sum3);