#include <stdio.h>
#include <unistd.h>
void main() 
{
    int val;  
    printf("hi\n");
  
    val = fork();   // line A
  
    if (val == 0)
      printf("hello from child process %d\n", val);  
    else if (val > 0)
      printf("hello from parent process %d\n", val);
  
}