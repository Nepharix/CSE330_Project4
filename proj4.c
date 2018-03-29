//Note: Haven't compiled code yet! As far as I know, steps 1-3 have been completed.
//
//===========================================
// CSE330 Project 4
// Code Written By:
// Ryan Christensen, 1209359849
// &
// Nestor Casillas, 1212985421
//===========================================

#include "sem.h"
#include <unistd.h>

//Global Variables
Semaphore * semaphore;
int array[3] = {0,0,0};
int array_counter = 0;

 
//Method Declarations
void method1_test();
void function1();
void function2();
void function3();

//void method2_test();

void main() {

RunQ = InitQueue();
    semaphore = InitSem(1);
   
   method1_test();
   printf("%d", array[0]);
   printf("%d", array[1]);
   printf("%d", array[2]);
   
   //method2_test(); 
   
   
}

void method1_test()  {
   printf("Beginning to test method 1");
   
   //Must create 3 childs.
   start_thread(child1);
   start_thread(child2);
   start_thread(child3);
   run();
   
   
   printf("This is the end statement. If you're seeing this, then there's an issue.");
}

void child1() {
   
   if(array_counter==2) {
      array_counter =0;
   }
   while(1) {
      P(Semaphore);
      array[array_counter]++;
      array_counter++;  
      sleep(1);
      V(Semaphore);
   }
}
   
void child2()  {
   if(array_counter==2) {
      array_counter =0;
   }
   while(1) {
      P(Semaphore);
      array[array_counter]++;
      array_counter++;
      sleep(1);
      V(Semaphore);
   }
}
   
void child3()  {
   
   if(array_counter==2) {
      array_counter =0;
   }
   while(1) {
      P(Semaphore);
      array[array_counter]++;
      array_counter++;
      V(Semaphore);
   }
}

/*void method2_test()  {
   printf("Beginning to test method 2");
   
   printf("This is the end of the method.\n");
   printf("If you're seeing this, then there's an issue.");
   
}*/
