import random
random_list=[];
for i in range(100):
    random_list.append(random.randint(100,900));
odd_list=[];
even_list=[];
prime_list=[];
for i in random_list:
    if i%2==0:
        even_list.append(i);
    else:
        odd_list.append(i);
    flag=0;
    for j in range(2,int(i/2)):
        if i%j==0:
            flag=1;
    if flag==0:
        prime_list.append(i);
print(odd_list);
print(even_list);
print(prime_list);5
