#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "tcb.h"

struct queue
{
   TCB_t * first;
}queue;

TCB_t * NewItem()
{
    //returns a pointer to a new TCB_t, uses memory allocation
   return (TCB_t*)malloc(sizeof(TCB_t));
}

void InitQueue(TCB_t ** head)
{
   *head = NULL;
}

void AddQueue(TCB_t ** head, TCB_t * item)
{
    //adds a queue item, pointed to by "item", to the queue pointed to by head.
   TCB_t * temp = *head;
   if(temp == 0)
   {
      *head = item;
      (*head)->next = *head;
      (*head)->prev = *head;
   }
   else if(temp->next == temp)
   {
      temp->next = item;
      temp->prev = item;
      item->next = temp;
      item->prev = temp;
   }
   else
   {
      while(temp->next != *head)
      {
         temp = temp->next;
      }
      item->next = temp->next;
      item->prev = temp;
      temp->next = item;
      (*head)->prev = item;
   }
}

TCB_t * DelQueue(TCB_t ** head)
{
    //deletes an item from head and returns a pointer to the deleted item.
    //if the queue is already empty, flag error.

    //points to the first element
   TCB_t * del = *head;
   if(del->next == del)
   {
      *head = NULL;
   }
   else
   {
      while(del->next != *head)
      {
         del = del->next;
      }
      del->prev->next = del->next;
      del->next->prev = del->prev;
   }
   return del;
}

void RotateQ(TCB_t ** head)
{
    //rotates the q_element head to become the tail, and the element after head becomes head
    //used for round robin scheduling
   if(head != 0)
   {
      TCB_t * temp = *head;
      *head = temp->next;
   }
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
