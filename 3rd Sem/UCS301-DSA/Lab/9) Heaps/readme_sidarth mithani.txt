leafchild of A[i]=A[2i]
rightchild of A[i]=A[2i+1]

parent of A[i]=A[floor(i/2)]

leafnodes --- > A[floor(n/2)+1,....n]  n is the number of nodes in the heap

//Heap is a special type of tree in which the node element has greater value than both its children
//Note for heaps we consider that the 1 index of the array holds the root of the heap tree
