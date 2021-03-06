#include "time.h"

void *task_body_time(void* pv)
{
  int i=0;
  time_t t;
  struct tm* curr_time;
  /* Get current time in seconds */
  t = time(NULL);
  /* Change the format to hh : mm : ss*/
  curr_time = localtime(&t);
  printf("%02d : %02d : %02d \n",curr_time->tm_hour, curr_time->tm_min, curr_time->tm_sec);
}

void get_current_Time()
{
  int i, n=10;
  pthread_t ptrarr[n];

  for(i=0; i<n; ++i)
  {
    /* Create a thread to get current time */
    pthread_create(&ptrarr[i], NULL, task_body_time, (void *)(__intptr_t)i);
    /* Sleep for 3 seconds */
    sleep(3);
  }
  for(i=0; i<n; i++)
  {
    pthread_join(ptrarr[i], NULL);
  }
}