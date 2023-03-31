#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: daysCalculatorA.c
 *   Author: Carson Mifsud
 *   Last Update: September 24, 2019
 *   Function: to print out the number of days between two given dates, including the starting date but excluding the final date
 *   Compilation: gcc -ansi -o daysCalculatorA daysCalculatorA.c
 *   Execution: ./daysCalculatorA 14 9 2019 9 12 2019
 */

int main ( int argc, char *argv[] ) {

   int monthLength[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
   int monthLengths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   int dd1 = 0;
   int mm1 = 0;
   int yyyy1 = 0;

   int dd2 = 0;
   int mm2 = 0;
   int yyyy2 = 0;
   int i;

   if ( argc > 7 || argc < 7) {
      printf ( "Usage: ./dayCalculator dd1 mm1 yyyy1 dd2 mm2 yyyy2 \n" );
      exit ( 1 );
   } else {
      dd1 = atoi ( argv[1] );
      mm1 = atoi ( argv[2] );
      yyyy1 = atoi ( argv[3] );
      dd2 = atoi ( argv[4] );
      mm2 = atoi ( argv[5] );
      yyyy2 = atoi ( argv[6] );
   }

   if ( yyyy1 != yyyy2 ) {
      printf ( "The two years entered are not equal, please re-enter two dates which have the same year\n" );
      exit( 1 );
   }

   if (mm1 >= 13 || mm1 <= 0 || mm2 >= 13 || mm2 <= 0) {
      printf ( "Error - the month entered is not in the proper range (1-12)\n");
      exit ( 1 );
   }
   if ( dd1 > monthLengths[mm1-1] ) {
      printf ( "Error - you entered %02d for the day and that is not in the range (1-%02d)\n", dd1, monthLengths[mm1-1] );
      exit ( 1 );
   }
   if ( dd2 > monthLengths[mm2-1] ) {
      printf ( "Error - you entered %02d for the day and that is not in the range (1-%02d)\n", dd2, monthLengths[mm2-1] );
      exit ( 1 );
   }

   dd1 = dd1 - 1;
   dd2 = dd2 - 1;

   int total1 = monthLength[mm1-1] + dd1;
   int total2 = monthLength[mm2-1] + dd2;

   if ( yyyy1 % 4 == 0 || yyyy2 % 4 == 0 ) {
      if ( yyyy1 % 400 == 0 || yyyy1 % 100 != 0 || yyyy2 % 400 == 0 || yyyy2 % 100 != 0) {
            for ( i = total1; i <= total2; i++ ) {
               if ( i == 59 ) {
                  total1 = total1 - 1;
               }
            }
      }
   }

   int total = total2 - total1;

   printf ( "%d\n", total );

}
