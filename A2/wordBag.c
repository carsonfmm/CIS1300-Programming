#include <stdio.h>
#include <string.h>
#include "textProc.h"

#define MAXSIZE  500
#define MAXWORDS 1000
/* Most code concepts in 'main' were gathered from Author Deb Stacey's program titled 'wordFind
 */ 

int main ( int argc, char *argv[] ) {
   char line[MAXSIZE];
   int i,j,k;
   int length;
   int numberOfWords;
   int wordCount[MAXWORDS];
   int words[MAXWORDS];

   while ( fgets ( line, MAXSIZE, stdin ) != NULL ) {
      chop ( line );
      convertLowerCase ( line );
      replaceDigits ( line );
      replacePunc ( line );
      reduceSpace ( line );
      trim ( line );

      length = strlen(line) + 1;
      j = 0;
      numberOfWords = 0;
      words[j++] = 0;
      for ( i=1; i<length; i++ ) {
         if ( line[i] == ' ' || line[i] == '\0' ) {
	    line[i] = '\0';
	    numberOfWords++;
	    words[j++] = i+1;
	 }
      }
      for ( i=0; i<numberOfWords; i++ ) {
	 if ( strlen(&line[words[i]]) > 5 ) {
            for ( j = 0; j < numberOfWords; j++ ) {
               if ( strlen(&line[words[j]]) > 5 ) {
                  if ( strlen(&line[words[i]]) == strlen(&line[words[j]]) ) {
                     wordCount[j]++;
                  }
               }
            }
	    printf ( "%03d %s\n", wordCount[j], &line[words[i]] );
	 }
      }

   } 


   return ( 0 );
}






int chop (char *line) {
   int lengthOfLine;
   int c;
   int i;

   if ( NULL == line ) {
      return ( -1 );
   }

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( c == 10 ) {
         *( line + i ) = 0;
      }
   }
   return ( 0 );
}


int convertLowerCase (char *line) {
   int lengthOfLine;
   int c;
   int i;
   int convertedToLowerCase = 0;

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( c > 64 && c < 91 ) {
         *( line + i ) = c + 32;
         convertedToLowerCase++;
      }
   }
   return ( convertedToLowerCase );
}

int replaceDigits (char *line) {
   int lengthOfLine;
   int c;
   int i;
   int digitsReplaced = 0;

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( c >= 48 && c <= 57) {
         *( line + i ) = 32 ;
         digitsReplaced++;
      }
   }
   return ( digitsReplaced );
}

int replacePunc (char *line) {
   int lengthOfLine;
   int c;
   int i;
   int punctuationReplaced = 0;

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 255) ) {
         *( line + i ) = 32;
         punctuationReplaced++;
      }
   }
   return ( punctuationReplaced );
}

int reduceSpace (char *line) {
   int lengthOfLine;
   int c;
   int temp;
   int i;
   int j = 1;
   int spacesReduced = 0;

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++ ) {
      c = *( line + i );
      temp = *( line + j );

      if ( ( c == 32 || c == 9 || c == 11 ) && ( temp == 32 || temp == 9 || temp == 11 ) ) {
         *( line + i ) = 127;
         spacesReduced++;
      }
      j++;
   }
   return ( spacesReduced );
}

int trim (char *line) {
   int lengthOfLine;
   int c;
   int i;
   int letter = 0;

   if ( NULL == line ) {
      return ( -1 );
   }

   lengthOfLine = strlen ( line );

   for ( i = 0; i < lengthOfLine; i++) {
      c = *( line + i );
      if ( ( c == 32 || c == 9 ) && letter == 0 ) {
         *( line + i ) = 127;
      }
      else if ( !( c == 32 || c == 9 ) ) {
         letter = 1;
      }
      if ( i + 1 == lengthOfLine ) {
         letter = 0;
         while ( ( *( line + i - 1 ) == 32 || *( line + i - 1 ) == 9 ) && letter == 0) {
            *( line + i -1 ) = 127;
            i--;
         }
         if ( !( *( line + i - 1) == 32 || *( line + i  - 1) == 9 ) ) {
            letter = 1;
         }
      }
   }
   return ( 0 );
}
