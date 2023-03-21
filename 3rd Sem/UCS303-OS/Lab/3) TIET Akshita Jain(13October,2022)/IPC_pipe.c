#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
  int pipefd[2];
  int ret;
  char buffer[20];

  pipe(pipefd);

  ret = fork();

  //parent process
  if (ret > 0)
  {
    fflush(stdin);
    printf("Parent Process \n");
    write(pipefd[1], "\n Hello from papa", 20);
    //write end of the pipe --> pipefd[1]
  }

  //child process
  if (ret ==0)
  {
    sleep(3);
    fflush(stdin);
    printf("\n Child Process");
    read(pipefd[0], buffer, sizeof(buffer));
    //read end of the pipe --> pipefd[0]

    // it will print the content in buffer
    printf("\n%s", buffer);
  }
}
