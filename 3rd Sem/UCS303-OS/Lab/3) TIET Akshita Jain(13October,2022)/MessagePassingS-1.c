// Writer Module for Message Queue using C Program
#include <stdio.h>
#include <sys/ipc.h> //contains definitions for the interprocess communication access structure
#include <sys/msg.h> //used for message queue structure
#include <sys/types.h> //defines a collection of typedef symbols and structures; like key_t here

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    int a;
} message;

int main()
{
    key_t key;
  //Unix requires a key of type key_t defined in file sys/types. h for requesting resources such as shared memory segments, message queues and semaphores
    int msgid, i;

    // STEP-1 is to generate a key
    // ftok to generate a key, where KEY will help to access the message queue
    key = ftok("vinay", 100);

    // STEP-2 is to create a message queue
    // msgid -> message identifier
    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    //Type of message, like, Message of type 1 or 2 or 3
    message.mesg_type = 1;

    printf("Enter Data 1: ");
    scanf("%d", &message.a);

   // STEP-3 is regarding message SEND
   // msgsnd to send message
   // The first argument, msgid, recognizes the message queue i.e., message queue identifier.
   //  The second argument, msgp, is the pointer to the message, sent and it is defined in the structure
   // The third argument, msgsz, is the size of message
   // 0 in end - The argument msgflg specifies the action to be taken in case message queue exceeds the maximum number of bytes allowed
  // The msgflg argument can be set to 0 (ignored), or like IPC_NOWAIT
  // IPC_NOWAIT :  If the message queue is full, then the message is not written to the queue, and control is returned to the calling process. If not specified, then the calling process will suspend (block) until the message can be written.
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    //printf("Data sent is : %d \n", message.a);

    return 0;
}



/*
struct mesg_buffer {
    long mesg_type;
    int a;
} message;
int main()
{
    key_t key;
    int msgid, i;
    key = ftok("vinay", 100);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Enter Data 1: ");
    scanf("%d", &message.a);

    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Data sent is : %d \n", message.a);
    return 0;
}
*/
