#include <stdio.h>
#include <stdlib.h>

int isLeap ( int year );

/*
 *   Program name: countLeaps.c
 *   Author: Carson Mifsud
 *   Last Update: October 22, 2019
 *   Compilation: gcc -ansi -o countLeaps countLeaps.c
 *   Execution: ./countLeaps.c (startYear) (numLeaps)
 */


int main ( int argc, char *argv[] ) {

   int startYear;
   int numLeaps;
   int total = 0;
   int leapYear;

   if ( argc > 3 || argc < 3) {
      printf ( "Usage: ./countLeaps.c (startYear) (numLeaps) \n" );
      exit ( 1 );
   } else {
      startYear = atoi ( argv[1] );
      numLeaps = atoi ( argv[2] );
   }

   while ( total != numLeaps ) {
         leapYear = isLeap ( startYear );
            if ( leapYear == 1 ) {
               printf ( "%d\n", startYear );
               total++;
               if ( total == numLeaps ) {
                  exit ( 1 );
               }
            }
   startYear++;
   }

return ( 0 );

}
