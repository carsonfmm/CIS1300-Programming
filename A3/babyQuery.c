#include <stdio.h>
#include <string.h>

/*  Defines */
#define MAXLENGTH 20
#define ROWS 200

/*
 *   Program name: babyQuery.c
 *   Author: Carson Mifsud
 *   Last Update: November 03, 2019
 *   Function:
 *   Compilation:
 *   Execution:
 */

/* Struct definitions */
struct pNames {
   int  year;
   int  rank[ROWS];
   char maleName[ROWS][MAXLENGTH];   
   int  maleNumber[ROWS];
   char femaleName[ROWS][MAXLENGTH];   
   int  femaleNumber[ROWS];
};
struct pNames name;

/* Function definitions */
int removeCommas ( char * );

int removeCommas (char *line ) {
   int lengthOfLine;
   int c;
   int i;
   int commasRemoved = 0;

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( (c == 44) ) {
         *( line + i ) = 127;
         commasRemoved++;
      }
   }
   return ( commasRemoved );
}

int main ( int argc, char *argv[] ) {

char* file1880 = "/home/cmifsud/CIS1300/Assignments/Assignment3/1880Names.txt";
int path;

printf ("What decade do you want to look at? [1880 to 2010]: ");
scanf ("%d", &name.year);

printf ("%d\n", name.year);

if (name.year == 1880) {
   fopen (file1880, "r");
}

printf ("Would you like to see the male (0), female (1), or both (2) name(s)? [0-2]: ");
scanf("%d", path);

printf ("%d\n", path);

}

