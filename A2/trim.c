#include <string.h>

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
