#include <string.h>

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
