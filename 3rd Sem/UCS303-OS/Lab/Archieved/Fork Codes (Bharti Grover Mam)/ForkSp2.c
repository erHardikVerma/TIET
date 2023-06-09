#include <stdio.h>
#include <unistd.h>
void main() 
{
    
  
    if (fork()||fork())   
    {
      fflush(stdout);
      printf("hi\n");  
    }
      fflush(stdout);
      printf("bye\n");
}