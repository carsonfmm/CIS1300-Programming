#include <string.h>

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
