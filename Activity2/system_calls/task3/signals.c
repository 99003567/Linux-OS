#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
// functions declarations 
void sighup(); 
void sigint(); 
void sigquit(); 
  
void main() 
{ 
    int pid; 

    // calling fork() for getting the child process 
    if ((pid = fork()) < 0)
    { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) 
    {
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;); 
    } 
  
    else /* parent */
    { /* pid holds id of child */
        printf("\nPARENT is sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT is sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT is sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
// sighup() function definition 
void sighup() 
  
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("CHILD has received a SIGHUP\n"); 
} 
  
// sigint() function definition 
void sigint() 
  
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("CHILD has received a SIGINT\n"); 
} 
  
// sigquit() function definition 
void sigquit() 
{ 
    printf("Child process is killed!!\n"); 
    exit(0); 
} 