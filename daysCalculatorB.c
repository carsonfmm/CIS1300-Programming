#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Program name: daysCalculatorB.c
 *   Author: Carson Mifsud
 *   Last Update: September 24, 2019
 *   Function: to print out the number of days between two given dates, including the starting date and giving the user an option to include the final date or exclude the final date
 *   Compilation: gcc -ansi -o daysCalculatorB daysCalculatorB.c
 *   Execution: ./daysCalculatorB 14 9 2019 9 12 2019 include(optional)
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

   char include;

   if ( argc < 7 || argc > 8) {
      printf ( "Usage: ./dayCalculator dd1 mm1 yyyy1 dd2 mm2 yyyy2 include(optional)\n" );
      exit ( 1 );
   }
   else if ( argc == 7 ) {
      dd1 = atoi ( argv[1] );
      mm1 = atoi ( argv[2] );
      yyyy1 = atoi ( argv[3] );
      dd2 = atoi ( argv[4] );
      mm2 = atoi ( argv[5] );
      yyyy2 = atoi ( argv[6] );

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

      if ( total1 > total2 ) {
         printf ( "You have entered a starting date which is past your ending date, this will result in a negative number. Please run the program again and enter correct credidentials\n" );
         exit ( 1 );
      }

      int total = total2 - total1;

      printf ( "%d\n", total );
   }

   else if ( argc == 8 ) {
      dd1 = atoi ( argv[1] );
      mm1 = atoi ( argv[2] );
      yyyy1 = atoi ( argv[3] );
      dd2 = atoi ( argv[4] );
      mm2 = atoi ( argv[5] );
      yyyy2 = atoi ( argv[6] );
      include = atoi ( argv[7] );

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

      if ( strcmp ( argv[7], "include" ) == 0) {
         dd2 = dd2 + 1;
      }

      int total1 = monthLength[mm1-1] + dd1;
      int total2 = monthLength[mm2-1] + dd2;

   if ( yyyy1 % 4 == 0 || yyyy2 % 4 == 0 ) {
      if ( yyyy1 % 400 == 0 || yyyy1 % 100 != 0 || yyyy2 % 400 == 0 || yyyy2 % 100 != 0) {
            for ( i = total1; i < total2; i++ ) {
               if ( i == 59 ) {
                  total1 = total1 - 1;
               }
            }
      }
   }

      if ( total1 > total2 ) {
         printf ( "You have entered a starting date which is past your ending date, this will result in a negative number. Please run the program again and enter correct credidentials\n" );
         exit ( 1 );
      }

      int total = total2 - total1;

      printf ( "%d\n", total );
   }

}
