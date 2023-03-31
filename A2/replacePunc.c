#include <string.h>

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
