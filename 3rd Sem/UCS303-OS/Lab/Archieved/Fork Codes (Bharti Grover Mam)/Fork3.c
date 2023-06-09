#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() 
{ 
  fork();
  fork();
  printf("hello \n");
  printf("hello \n");
  
}
  