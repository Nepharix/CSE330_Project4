 //===========================================
// CSE330 Project 3
// Code Written By:
// Ryan Christensen, 1209359849
// &
// Nestor Casillas, 1212985421
//===========================================

#include "sem.h"
#include <unistd.h>

int global = 0;
Semaphore * semaphore;
void method1_test();
void funcion1();
void function2();

int wwc, wc, rwc, rc;
void method2_test();
void producer1();
void producer2();
void consumer1();
void consumer2();

void producer1()
{

}
void producer2()
{

}
void consumer1()
{

}
void consumer2()
{

}

void function1()
{
    int local = 0;
    while(1)
    {
        P(semaphore);
        printf("SECTION 1: Global: %d, Local: %d\n", global, local);
        global++;
        local++;
        sleep(1);
        V(semaphore);
    }
}

void function2()
{
    int local = 0;
    while(1)
    {
        P(semaphore);
        printf("SECTION 2: Global: %d, Local: %d\n", global, local);
        global++;
        local++;
        sleep(1);
        V(semaphore);
    }
}

void method1_test()
{
    printf("Running Method 1:\n");

    start_thread(function1);
    start_thread(function2);
    
    run();
}
int main()
{
    RunQ = InitQueue();
    semaphore = InitSem(1);

    method1_test();

    return 0;
}   

void method2_test()  {
/*Method 2:
   Write a producer consumer solution, using the code given in class (see notes).   
   Run 2 producers and 2 consumers. You will have to work out some details. 
   If you choose to do this you really should do method 1 first. 
   Also, doing this will make it easier for you to do project 4.*/
   
   
   /* Note: Method 2 test should be extremely similar to pseudocode.
   Must implement sem.h first in order to test though.
   Pseudo Code given in class(13): 
   printf("Initializing method 2 test");
   Reader Entry
      P(mutex);
         if(wwc>0) or (wc > 0)   {
            rwc++
            V(mutex);
            P(rsem);
            P(mutex);
            rwc--;   
         }
         rc++
         V(mutex);
      }   
   Reader Exit
      P(mutex);
      rc--;
      if ((rc == 0) && (wwc>0)   {
         V(wsem);
      }
      V(mutex);
   }
          
      Writer Entry
         P(mutex);
         if ((rc>0) || (wc > 0)) {
            wwc++
            V(mutex);
            P(wsem)
            P(mutex);
            wwc; 
         }
         wc++;
         V(mutex);
      }   
      Writer Exit
         P(mutex);
         wc--;
         if(rwc>0)   {
            for (i = 1; i <= rwc; i++) [
               V(resem);
            }
         }   
      }
          
   */
   
   printf("Test has been completed.");

}
