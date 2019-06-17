        /* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {

   int res = 0;			// Creating a variable to save the value return by the fscanf function.
   unsigned int length = 0u;	// Initializing the variable with a positive 0 (remember the unsigned int type). 
   FILE *fpointer = NULL;	// Assigning a "safe" value to the pointer.
   
   fpointer = fopen (filepath, "r"); // Storing the value returned by fopen in fpointer, and setting the read mode.

   /* If the execution of the fopen function goes well it will return a FILE pointer.
    * Otherwise NULL is returned and errno is set to indicate an error. */

   if ( fpointer == NULL ) {
	   fprintf (stderr, "File does not exists");

	   /* The function fprintf allows to select the desire output stream,
	    * so, the upper line displays a message in stderr stream. */
	   
	   exit (EXIT_FAILURE);	// Close the stderr stream.

	   /* The stdio macros are closed by a call of exit or
	    * by a normal program termination. */
   }

   // The next fscanf is needed to know the size of the array.
   
   res = fscanf (fpointer, "%u", &length);	// Assign the value returned by fscanf to res.
   						// This allows us to analyse the success of the function.

   /* The fscanf scans input according to the specified format, in this case, "unsigned int".
    * And it reads input from the specified stream, again, in this case, "fpointer".
    * If the function success, this function returns the number of input items successfully matched and assigned.
    * Or in the worst case a 0, in the event of an early matching failure.
    * If it not success, it returns the value EOF (End Of File). */

   if ( res == 0 || res == EOF ) {
	   fprintf (stderr, "Invalid array\n");
	   exit (EXIT_FAILURE);	// Closing the stderr stream.
   }

   // In the event that the size of the array stored in the file exeeds the 100000 elements.
 
   if ( max_size < length ) {	
	fprintf(stderr, "Allowed size is: %d \n", max_size); 
	exit (EXIT_FAILURE);
   }

   // Loop to store the values of the file in the array.

   for (unsigned int i = 0u; i < length; ++i) {		// 0u to indicate the positive zero.
       res = fscanf(fpointer, "%d", &(array[i]));	// The brackets are dispose to make explicit the precedence.
       if ( res == 0 ) {
	       fprintf (stderr, "Invalid array \n");
	       exit (EXIT_FAILURE);
       }
   }
    
   fclose (fpointer);	// This tells the system that the file isn't been using anymore.
   return length; 


}

// Function to display the array on the screen.

void array_dump(int a[], unsigned int length) {

    unsigned int i;
    printf ("[ ");
    for (i = 0u; i < length; ++i){	// Another 0u (positive zero).
         printf ("%i", a[i]);
          if   (i != length - 1)	// When the array reaches the end, you can't print a coma.
                printf (", ");
          else
                printf (" ");
	} 
   printf ("]\n"); 			
       
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return (EXIT_SUCCESS);
}
