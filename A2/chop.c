#include <string.h>

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
