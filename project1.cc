/////////////////////////////////////////////////////////////////////////
//  Create threads in Nachos
//

#include "list.h"
#include "system.h"
#include "synch.h"
#include "testcase.h"
#include <unistd.h>

Thread *th1;
Thread *th2;
int global = 1;

// running for calculation. Recommend that t values from 1 to 10
// Do NOT modify this function
void running_for_calculation(int t)
{
        int s = 0, j = 0;
        for (j = 0 ; j < 10000 * t ; j ++)
                s = s + j;
        currentThread->Yield();
}

//latter running thread
//you are REQUIRED to modify this function to see different result
void latter_thread(int arg)
{
        // Store current thread name to var threadname. Do NOT modify.
        char * threadname = currentThread->getName();
        printf("Hello, my name is %s\n", threadname);
        int times = arg * 10000;
        printf("This thread is %s and it will be performed %d times\n", threadname, times);
        running_for_calculation(arg);
        // (Task-Comment 1) -Task 2: Add your code here to get the priority and output it to screen.
        // (Task-Comment 2) -Task 3: Add your code here in Step 1


        // (Task-Comment 3) -Task 2: Add your code here to output the calculation information
        // (Task-Comment 4) -Task 2: Add your code here to invoke the calculation
        int times = arg * 10000;
        printf("This thread is %s and it will be performed %d times\n", threadname, times);


        global *= 5;

        // (Task-Comment 5) -Task 3: Add your code here to output the value of the global variable

        printf ("%s ends\n", threadname);

        // (Task-Comment 6) -Task 3: Add your code here in Step 1
}

//prior running thread
void prior_thread(int arg)
{
        // Store current thread name to var threadname. Do NOT modify.
        char * threadname = currentThread->getName();

        printf ("Hello, my name is %s\n", threadname);

        // (Task-Comment 7) -Task 2: Add your code here to get the priority and output it to screen.

        // (Task-Comment 8) -Task 3: add your code here in Step 4

        // (Task-Comment 9) -Task 2: Add your code here to output the calculation information

        // (Task-Comment 10) -Task 2: Add your code here to invoke the calculation

        // (Task-Comment 11) -Task 3: Add your code here in Step 6

        global += 3;
        // (Task-Comment 12) -Task 3: Add your code here to output the value of the global variable

        printf ("%s ends\n", threadname);

        // (Task-Comment 13) -Task 3: add your code here in Step 4
}

void project1()
{
        latter_thread(1);
        th1 = new Thread("Thread1");
        th1->Fork(prior_thread, 6);
        // (Task-Comment 14) -Task 2: Add your code here to create Thread2