#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "tcb.h"

typedef struct queue
{
   struct TCB_t * head;
}queue;

struct queue * RunQ;

TCB_t * NewItem()
{
    //returns a pointer to a new TCB_t, uses memory allocation
   struct TCB_t * tcb = (TCB_t*)malloc(sizeof(TCB_t));
   tcb->prev = NULL;
   tcb->next = NULL;
   return tcb;
}

struct queue * InitQueue()
{
   return (struct queue *) malloc(sizeof(struct queue));
}

void AddQueue(struct queue * queue, TCB_t * element)
{
    //adds a queue item, pointed to by "item", to the queue pointed to by head.
    if(queue->head == NULL)
    {
        queue->head = element;
        queue->head->prev = queue->head;
        queue->head->next = queue->head;
    }
    else
    {
        TCB_t * temp = queue->head->prev;
        temp->next = element;
        element->prev = temp;
        temp = temp->next;
        temp->next = queue->head;
        queue->head->prev = temp;
    }
}

struct TCB_t * DelQueue(struct queue * queue)
{
   if(queue->head == NULL)
    {
        return NULL;
    }
    else if (queue->head->next == queue->head)
    {
        TCB_t * temp = queue->head;
        queue->head = NULL;
        return temp;
    }
    else
    {
        TCB_t * temp1 = queue->head;
        TCB_t * temp2 = queue->head->prev;
        if(queue->head->next == queue->head)
        {
            queue->head = NULL;
        }
        else
        {
            queue->head = queue->head->next;
            queue->head->prev = temp2;
            temp2->next = queue->head;
        }
        return temp1;
    }
}

void RotateQ(struct queue * queue)
{
    //rotates the q_element head to become the tail, and the element after head becomes head
    //used for round robin scheduling
    queue->head = queue->head->next;
}

void printQueue(TCB_t * head)
{
   if(head == NULL)
   {
      puts("Queue is NULL");
      return;
   }
   if(head->next == head)
   {
      printf("%p\n", head);
   }
   else
   {
      TCB_t * current = head;
      while(current != head)
      {
         printf("%p\n", current);
         current = current->next;
      }
   }
}
