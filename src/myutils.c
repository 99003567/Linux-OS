#include "myutils.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdarg.h>
 
long factorial(int n)
{
   int c;
   long result = 1;
 
   for( c = 1 ; c <= n ; c++ )
         result = result*c;
 
   return result;
}



int checkPalindrome(int number)
{
  int temp, remainder, rev=0;
  temp = number;

  while( number!=0 )
  {
     remainder = number % 10;
     rev = rev*10 + remainder;
     number /= 10;
  }

  if ( rev == temp ) return 0;
  else return 1;
}

 

 int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}

int vsum(int a, ...) 
{
    // define type of variable
    va_list L;
    int z;

    z = 0;

    va_start(L, a);

    // Loop to adding the int values
    for (int i=0; i < a; i++)
    {
        z = z + va_arg(L, int);
    }

    va_end(L);

    return z;
}
