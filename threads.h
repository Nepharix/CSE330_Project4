#include "q.h"

extern TCB_t * RunQ;

void start_thread(TCB_t * tcb, void (*function)(void))
{
   void * stack = (void *) malloc(8192);	
   tcb = (TCB_t *) malloc(sizeof(TCB_t));
   init_TCB(tcb, function, stack, 8192);

   AddQueue(&RunQ, tcb);
}

void run()
{
   TCB_t * Curr_Thread = RunQ;
   ucontext_t parent;     // get a place to store the main context, for faking
   getcontext(&parent);   // magic sauce
   swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

void yield()
{
   TCB_t * Prev_Thread = RunQ;
   RotateQ(&RunQ);
   TCB_t * Curr_Thread = RunQ;
   swapcontext(&(Prev_Thread->context), &(Curr_Thread->context));
}


