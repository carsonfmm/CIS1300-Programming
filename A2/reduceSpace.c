#include <string.h>

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
