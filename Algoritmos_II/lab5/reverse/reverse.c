#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "stack_.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./reverse <string-to-reverse>\n");
        exit(EXIT_FAILURE);
    }
    char *str = argv[1];

    size_t length = strlen(str);
    /* the function strlen() computes the length of the string
     * up to, but not including the null character.
     * This is an important consideration if you want to print
     * the string.
     * A null character, if printed from the output, 
     * could indicate the end of the output and avoid any other output.
    */
    stack_head str_rev = stack_empty();
    
    for ( unsigned int i = 0u; i < length; ++i )
	    str_rev = stack_push(str_rev,str[i]); // Saving the word into the stack.

    for ( unsigned int i = 0u; i < length; ++i ) {
	    str[i] = stack_top(str_rev); // Re-storing the stack on the string.
            str_rev = stack_pop(str_rev); // Taking out the used element from the stack.
    }

    printf("%s\n", str);
}
