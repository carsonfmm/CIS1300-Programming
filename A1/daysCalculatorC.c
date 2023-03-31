#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Program name: daysCalculatorC.c
 *   Author: Carson Mifsud
 *   Last Update: September 24, 2019
 *   Function: to print out the number of days between two given dates typed with dashes, including the starting date and giving the user an option to include the final date or exclude the final date
 *   Compilation: gcc -ansi -o daysCalculatorC daysCalculatorC.c
 *   Execution: ./daysCalculatorC 14-9-2019 9-12-2019 include(optional)
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

   if ( argc < 3 || argc > 4) {
      printf ( "Usage: ./dayCalculator dd1-mm1-yyyy1 dd2-mm2-yyyy2 include(optional)\n" );
      exit ( 1 );
   }
   else if ( argc == 3 ) {

      char dayStr1[3];
      dayStr1[0] = argv[1][0];
      dayStr1[1] = argv[1][1];
      dayStr1[2] = '\0';
      dd1 = atoi(dayStr1);

      char mmStr1[3];
      mmStr1[0] = argv[1][3];
      mmStr1[1] = argv[1][4];
      mmStr1[2] = '\0';
      mm1 = atoi(mmStr1);

      char yyyyStr1[6];
      yyyyStr1[0] = argv[1][6];
      yyyyStr1[1] = argv[1][7];
      yyyyStr1[2] = argv[1][8];
      yyyyStr1[3] = argv[1][9];
      yyyyStr1[4] = '\0';
      yyyy1 = atoi(yyyyStr1);

      char dayStr2[3];
      dayStr2[0] = argv[1][11];
      dayStr2[1] = argv[1][12];
      dayStr2[2] = '\0';
      dd2 = atoi(dayStr2);

      char mmStr2[3];
      mmStr2[0] = argv[1][14];
      mmStr2[1] = argv[1][15];
      mmStr2[2] = '\0';
      mm2 = atoi(mmStr2);

      char yyyyStr2[6];
      yyyyStr2[0] = argv[1][17];
      yyyyStr2[1] = argv[1][18];
      yyyyStr2[2] = argv[1][19];
      yyyyStr2[3] = argv[1][20];
      yyyyStr2[4] = '\0';
      yyyyStr2[5] = '\0';
      yyyy2 = atoi(yyyyStr2);

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

   else if ( argc == 4 ) {

      char dayStr1[3];
      dayStr1[0] = argv[1][0];
      dayStr1[1] = argv[1][1];
      dayStr1[2] = '\0';
      dd1 = atoi(dayStr1);

      char mmStr1[3];
      mmStr1[0] = argv[1][3];
      mmStr1[1] = argv[1][4];
      mmStr1[2] = '\0';
      mm1 = atoi(mmStr1);

      char yyyyStr1[6];
      yyyyStr1[0] = argv[1][6];
      yyyyStr1[1] = argv[1][7];
      yyyyStr1[2] = argv[1][8];
      yyyyStr1[3] = argv[1][9];
      yyyyStr1[4] = '\0';
      yyyy1 = atoi(yyyyStr1);

      char dayStr2[3];
      dayStr2[0] = argv[1][11];
      dayStr2[1] = argv[1][12];
      dayStr2[2] = '\0';
      dd2 = atoi(dayStr2);

      char mmStr2[3];
      mmStr2[0] = argv[1][14];
      mmStr2[1] = argv[1][15];
      mmStr2[2] = '\0';
      mm2 = atoi(mmStr2);

      char yyyyStr2[6];
      yyyyStr2[0] = argv[1][17];
      yyyyStr2[1] = argv[1][18];
      yyyyStr2[2] = argv[1][19];
      yyyyStr2[3] = argv[1][20];
      yyyyStr2[4] = '\0';
      yyyyStr2[5] = '\0';
      yyyy2 = atoi(yyyyStr2);

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

      include = atoi(argv[3]);

      dd1 = dd1 - 1;
      dd2 = dd2 - 1;

      if ( strcmp ( argv[3], "include" ) == 0) {
         dd2 = dd2 + 1;
      }

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

}
