#include "threads.h"

typedef struct Semaphore   {

//Method Description: A value field and a queue of TCBs.

//Queue of TCBs here
int value;


}Semaphore;

void InitSem(sempahore, value)   {
/*Method Description: Initializes the value field with the specified value.*/
}

void P(semaphore) {
/*Method Description: The P routine decrements the semaphore, and if the value is less than zero then 
blocks the thread in the queue associated with the semaphore 
(Curr_thread get added to semaphore queue and a new thread 
is selected from ReadyQ and put in Curr_Thread – and then swapcontext.) */
}

void V(sempahore) {
/* Method Description: The V routine increments the semaphore, and if the value is 0 or negative, 
then takes a PCB out of the semaphore queue and puts it into the ReadyQ queue. 
Note: The V routine also "yields" to the next runnable thread. //this is important.*/
}


