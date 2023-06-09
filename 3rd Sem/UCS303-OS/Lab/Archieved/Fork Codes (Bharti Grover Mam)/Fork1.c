#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void main ()
{
   if (fork()&&fork())
   {
     printf("hello");
   } 
 }
