#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *fp1, *fp2; 
    char c; 
  
    // Opening file1.txt in read mode
    fp1 = fopen("file1.txt", "r"); 
    if (fp1 == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Opening file2.txt in write mode 
    fp2 = fopen("file2.txt", "w"); 
    if (fp2 == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Reading contents from file1.txt and copying its contents to file2.txt
    c = fgetc(fp1); 
    while (c != EOF) 
    { 
        fputc(c, fp2); 
        c = fgetc(fp1); 
    } 
  
    printf("\nContents copied to file2 from file1."); 
  
    fclose(fp1); 
    fclose(fp2); 
    return 0; 
}