#include "mystring.h"
#include<stdio.h>
#include<string.h>

int mystrlen(char* str1)
{
    return strlen(str1);
}

char* mystrcpy(char* abc, const char* str1)
{
    abc = strcpy(abc, str1);
    return abc;
}

char* mystrcat(char *str3, const char *str4)
{
    strcat(str3, str4);
    return str3;
}

int mystrcmp(const char* str5, const char* str6)
{
    return strcmp(str5, str6); 
}
