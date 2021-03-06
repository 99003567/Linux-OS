#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// defining the macro size of array 
#define max 9
  
// defining the macro Max number of thread 
#define Th_max 3
  
// Array declaration 
int arr[max] = { 1, 4, 9, 10, 12, 14, 17, 21, 23 }; 
  
// Array to store max of threads 
int max_num[Th_max] = { 0 }; 
int thread_no = 0; 
  
// Function to find maximum 
void max_elements(void* arg) 
{ 
    int i, num = thread_no++; 
    int maxs = 0; 
  
    for (i = num * (max / 3); i < (num + 1) * (max / 3); i++) { 
        if (arr[i] > maxs) 
            maxs = arr[i]; 
    } 
  
    max_num[num] = maxs; 
} 
  
int main() 
{ 
    int maxs = 0; 
    int i; 
    pthread_t threads[Th_max]; 
  
    // creating 3 threads 
    for (i = 0; i < Th_max; i++) 
        pthread_create(&threads[i], NULL, 
                       max_elements, (void*)NULL); 
  
    // joining 3 threads 
    for (i = 0; i < Th_max; i++) 
        pthread_join(threads[i], NULL); 
  
    // Finding max element in an array 
    // by individual threads 
    for (i = 0; i < Th_max; i++) { 
        if (max_num[i] > maxs) 
            maxs = max_num[i]; 
    } 
  
    printf("Maximum Element is : %d", maxs); 
  
    return 0; 
} 