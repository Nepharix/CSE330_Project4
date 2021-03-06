#include "threads.h"

typedef struct Semaphore {
//Method Description: A value field and a queue of TCBs.
//Queue of TCBs here
    int value;
    struct queue * TCB_queue;
}Semaphore;

Semaphore * InitSem(int value)   {
/*Method Description: Initializes the value field with the specified value.*/
    Semaphore * semaphore = (struct Semaphore *)malloc(sizeof(struct Semaphore));
    semaphore->TCB_queue = InitQueue();
    semaphore->value = value;
    return semaphore;
}

void P(Semaphore * semaphore) {
/*Method Description: The P routine decrements the semaphore, and if the value is less than zero then 
blocks the thread in the queue associated with the semaphore 
(Curr_thread get added to semaphore queue and a new thread 
is selected from ReadyQ and put in Curr_Thread – and then swapcontext.) */

    semaphore->value--;
    if(semaphore->value < 0)
    {
        struct TCB_t * t = DelQueue(RunQ);
        AddQueue(semaphore->TCB_queue, t);
        swapcontext(&(t->context), &(RunQ->head->context));
    }
}

void V(Semaphore * semaphore) {
/* Method Description: The V routine increments the semaphore, and if the value is 0 or negative, 
then takes a PCB out of the semaphore queue and puts it into the ReadyQ queue. 
Note: The V routine also "yields" to the next runnable thread. //this is important.*/

    

    semaphore->value++;
    if(semaphore->value <= 0)
    {
        struct TCB_t * t = DelQueue(semaphore->TCB_queue);
        AddQueue(RunQ, t);
    }
    yield();
}


