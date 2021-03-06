#include"pipes.h"
void main() 
{
    int i;
    i = mkfifo("pipe1",0666);
    if(i<0)
        printf("\npipe1 was not created");
    else
        printf("\npipe1 created");
    int j;
    j = mkfifo("pipe2",0666);
    if(j<0)
        printf("\npipe2 was not created");
    else
        printf("\npipe2 is created\n");
}
