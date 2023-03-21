// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    int a;
} message;

int main()
{
    key_t key;
    int msgid;

  // ftok to generate unique key
    key = ftok("vinay", 100);

    // msgget creates a message queue and returns identifier
    // The first argument, key, recognizes the message queue. The key can be either an arbitrary value or one that can be derived from the library function ftok().
    msgid = msgget(key, 0666 | IPC_CREAT);

   // msgrcv to receive message
   // 4th para = message type
   // 5th para = msgflg (message flag)
    msgrcv(msgid, &message, sizeof(message), 1, 0);

     // display the message
    printf("Data Received is : %d \n", message.a);
  
  // to destroy the message queue
    //msgctl(msgid, IPC_RMID, NULL);
  
    return 0; 

}
