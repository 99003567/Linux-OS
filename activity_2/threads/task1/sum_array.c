#include <stdio.h>
#include <pthread.h> 
  
// size of array 
#define MAX 9 
  
// maximum number of threads 
#define MAX_THREAD 3 
  
int arr[] = { 1, 4, 9, 10, 12, 14, 17, 21, 23 }; 
int sum[3] = { 0 }; 
int part = 0; 
  
void* sum_of_arr(void* arg) 
{ 
  
    // Each thread computes sum of 1/4th of array 
    int thread_part = part++; 
  
    for (int i = thread_part * (MAX / 3); i < (thread_part + 1) * (MAX / 3); i++) 
        sum[thread_part] += arr[i]; 
} 
  
// Driver Code 
int main() 
{ 
  
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 3 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_of_arr, (void*)NULL); 
  
    // joining 3 threads i.e. waiting for all 3 threads to complete 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 3 parts 
    int total = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total += sum[i]; 
  
    printf("sum is %d",total);
  
    return 0; 
} 
