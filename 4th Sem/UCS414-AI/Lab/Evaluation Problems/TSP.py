#create a matrix kind of list (here 2 dimensional list) to
#store the cost between cities

graph=[[0, 10, 15, 20],
       [10, 0, 35, 25],
       [15, 35, 0, 30],
       [20, 25, 30, 0]]
from itertools import permutations
l = list(permutations(range(1, 4+1))) 
print (l)                       #to print 
min=999                         #cost
for x in l:
    if x[0]==1:         # as city 1 is taken as source city, only list element with first element as 1 will be treated for further operation
        print ("the route is :", x) 
        sum=0
    
        for j in range(0,len(x)):
            if (j==(len(x)-1)):
                sum=sum+graph[x[j]-1][x[0]-1]
                print("the cost of route is: ",sum)
            else:
                sum=sum+graph[x[j]-1][x[j+1]-1]
                #print("sum is: ",sum)
                
                
        if sum<min:
            min=sum
            temp=x
        

print("the best route is :",temp)
print("cost of the route is :",min)

        


            

        
        

    
