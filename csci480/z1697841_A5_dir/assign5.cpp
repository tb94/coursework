
    //******************************************************//
    //                      CSCI 480                        //
    //        Assignment 5 - Process Synchronization        //
    //                                                      //
    // This program creates threads to add and remove       //
    // widgets                                              //
    //                                                      //
    // Programmer - Tim Bretz                               //
    //                                                      //
    // Date - 10/27/17                                      //
    //******************************************************//                                           

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define P_NUMBER 6
#define C_NUMBER 4
#define BUFFER_SIZE 12
#define N_P_STEPS 4
#define N_C_STEPS 6

using namespace std;

int counter;
sem_t notFull;
sem_t notEmpty;
pthread_mutex_t mutex;

// insert a widget and increment counter //

void * insert(void * threadid)
{
    pthread_mutex_lock(&mutex);

    counter++;
    printf("Producer %li inserted one item.\tTotal is now %d\n", (long)threadid, counter);

    pthread_mutex_unlock(&mutex);
}

// remove a widget and decrement counter //

void * remove(void * threadid)
{
    pthread_mutex_lock(&mutex);

    counter--;
    printf("Consumer %li removed one item.\tTotal is now %d\n", (long)threadid, counter);

    pthread_mutex_unlock(&mutex);
}

// insert widget when there is room //

void * produce(void * threadid)
{
    for (int i = 0; i < N_P_STEPS; i++)
    {
        sem_wait(&notFull);
        insert(threadid);
        sem_post(&notEmpty);
    }
    
    pthread_exit(NULL);
}

// consume widget when at least one exists //

void * consume(void * threadid)
{
    for (int i = 0; i < N_C_STEPS; i++)
    {
        sem_wait(&notEmpty);
        remove(threadid);
        sem_post(&notFull);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t consumer[C_NUMBER];
    pthread_t producer[P_NUMBER];
    int rc;
    long t;
   
    cout << "\nProducer Comsumer Simulation\n";

    // initialize semaphores //

    sem_init(&notFull, 0, BUFFER_SIZE);

    sem_init(&notEmpty, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    cout << "\nSemaphores and mutex have been initialized.\n" << endl;

    // create threads to call respective functions // 

    for(t = 0; t < P_NUMBER; t++)
    {
        rc = pthread_create(&producer[t], NULL, produce, (void *) t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create(producer) is %d\n", rc);
            exit(-1);
        }
    }

    for(t = 0; t < C_NUMBER; t++)
    {
        rc = pthread_create(&consumer[t], NULL, consume, (void *) t);
        if(rc)
        {
            printf("ERROR; return code from pthread_create(consumer) is %d\n", rc);
            exit(-1);
        }
    }

    for(t = 0; t < P_NUMBER; t++)
    {
        pthread_join(producer[t], NULL);
    }

    for(t = 0; t < C_NUMBER; t++)
    {
        pthread_join(consumer[t], NULL);
    }

    cout << "\nAll threads have been closed.\n";

    // destroy semaphores and mutex //

    sem_destroy(&notFull);
    sem_destroy(&notEmpty);
    pthread_mutex_destroy(&mutex);

    cout << "\nAll semaphores and mutex have been deleted.\n" << endl;


    return 0;
}

