#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include<stdio.h>
#include<string.h>
int main()
{   
    int number1 = 1001;
    int number2 = 1231;
    int k =4;
    int factnum = 5;
    int num = 5;
    long fact = 1;
    int result;
    char city[20] = "HYDERABAD";
    char eq1[20] = "ABCD";
    char eq2[20] = "ABCD";
    char town[20] = "MANGALORE";
    char abc[20];
    printf("%d is the string length.\n",mystrlen(city));
    printf("%s\n",mystrcpy(abc,city));
    printf("%s\n",mystrcat(city,town));
     printf("Strings are equal. Value returned by the strcmp() is %d\n",mystrcmp(eq1,eq2));
    printf("Strings are unequal. Value returned by the strcmp() is %d\n",mystrcmp(city,town));
    printf("factorial of %d is %ld \n",factnum,factorial(factnum));
    if(checkPalindrome(number1) == 0){
        printf("%d is a palindrome number.\n",number1);}
    else if(checkPalindrome(number1) == 1){
        printf("%d is not a palindrome number.\n",number1);
    }
    if(checkPalindrome(number2) == 0){
        printf("%d is a palindrome number.\n",number2);}
    else if(checkPalindrome(number2) == 1){
        printf("%d is not a palindrome number.\n",number2);
    }
    result = check_prime(86);
    if ( result == 1 ){
      printf("It is prime number.\n");
    }
   else if(result == 0){
      printf("It is not prime number.\n");
   }
    printf("%d\n", vsum(3, 2, 3, 4));
    printf("setting %d th of %d is %d \n",k,num,set(num,k));
    printf("setting %d th of %d is %d \n",k,num,clear(num,k));
    printf("setting %d th of %d is %d \n",k,num,flip(num,k));
     printf("setting %d th of %d is %d \n",k,num,query(num,k));
    return 0;
}