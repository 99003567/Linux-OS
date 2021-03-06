/*program to implement producer consumer problem using Stack operations using semaphores*/

#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define Max_items 5 // Maximum items a producer can produce or a consumer can consumer
#define Buffer_size 5 // Size of the buffer

sem_t full; // creating a semaphore full 
sem_t empty; // creating a semaphore empty

int in = 0;
int out = 0;
int item=0;
int buffer[Buffer_size];


void *consumer(void *con_num)
{   
    if(out==Buffer_size-1)
    {
        printf("stack is empty right now so the consumer can't consume anything\n");
    }
    else
    {
     int item=0;
     for(int i = 0; i < Max_items; i++) {
        sem_wait(&full);
        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)con_num),item, out); 
        out = (out + 1) % Buffer_size;     
        sem_post(&empty);
     }
    }
}

void *producer(void *prod_num)
{   
    if(in==Buffer_size-1)
    {
        printf("stack is full right now so Producer can produce \n");
    }
    else
    {
     for(int i = 0; i < Max_items; i++) {
        item = rand(); // Produce a random item
        sem_wait(&empty);
        /* put value item into the buffer */
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)prod_num),buffer[in],in);
        in = (in + 1) % Buffer_size;     
        sem_post(&full);
     }
    }
}

int main()
{   
    pthread_t prod[10],cons[10]; // making instances of pthread
    sem_init( &empty,0,Buffer_size); //initialize the declared semaphores 
    sem_init( &full,0,0);
    int arr[10] = {1,2,3,4,5}; // array of size 5
    for(int i = 0; i < 10; i++) {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&arr[i]); //creates the thread prod which will be executing till it’s in producer method.
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&arr[i]); //creates the thread cons which will be executing till it’s in consumer method.
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(cons[i], NULL);
    }
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
