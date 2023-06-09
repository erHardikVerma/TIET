#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
  // ftok to generate unique key
  key_t key = ftok("shmfile",65);

  // returns an identifier for the shared memory segment
  // 1024 is the number of bytes
  int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

  //Before one can use a shared memory segment, their is a need to attach to it using shmat().
  //shmid is shared memory id.
  //shmaddr specifies specific address to use but we should set
  //it to zero and OS will automatically choose the address.
  //(void*)0 = this means NULL
  //second argument is shmaddr, and this specifies the attaching address. If shmaddr is NULL, the system by default chooses the suitable address to attach the segment.
  //3rd argument is FLAG. There are 4 flags. SHM_RDONLY, SHM_RND, SHM_REMAP, SHM_EXEC. Passing the value 0 means that all flags are unset.
  char *str = (char*) shmat(shmid,(void*)0,0);

  printf("Write Data : ");
  scanf("%s", str);

  printf("Data written in memory: %s\n",str);

  //detach from shared memory
  shmdt(str);

  return 0;
}

/*
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
  key_t key = ftok("shmfile",65);
  int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
  char *str = (char*) shmat(shmid,(void*)0,0);

  printf("Write Data : ");
  scanf("%s", str);
  printf("Data written in memory: %s\n",str);

  shmdt(str);
  return 0;
}
*/
