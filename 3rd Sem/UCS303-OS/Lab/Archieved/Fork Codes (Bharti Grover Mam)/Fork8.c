#include <stdio.h>
#include <unistd.h>

void main()
{
  int x;
  x=fork();
  if (x==0)
  {
    printf("Process id of child = %d", getpid());
    printf("\n");
    printf("value of x for child = %d", x);
    printf("\n");
  }
  else
  {
    printf("Process id of parent = %d", getpid());
    printf("\n");
    printf("value of x for parent= %d", x);
    printf("\n");
  }
}
