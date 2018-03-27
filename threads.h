#include "q.h"

void start_thread(void (*function)(void))
{
   void * stack = (void *) malloc(8192);	
   TCB_t * tcb = (TCB_t *) malloc(sizeof(TCB_t));
   init_TCB(tcb, function, stack, 8192);
   AddQueue(RunQ, tcb);
}

void run()
{
   TCB_t * Curr_Thread = RunQ->head;
   ucontext_t parent;     // get a place to store the main context, for faking
   getcontext(&parent);   // magic sauce
   swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

void yield()
{
   ucontext_t current;
   getcontext(&current);
   RunQ->head->context = current;
   RotateQ(RunQ);
   ucontext_t new_context = RunQ->head->context;
   swapcontext(&current, &new_context);
}


