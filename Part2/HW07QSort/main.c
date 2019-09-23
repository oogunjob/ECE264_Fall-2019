// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw07.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{

  // if argc is not 3, return EXIT_FAILURE
  if(argc != 3)
  {
	fprintf(stderr, "An error occured because argc was not equal to 3.\n");
    return EXIT_FAILURE;
  }

  // counts the number of integers in the file
  int numElem = 0;
  numElem = countInt(argv[1]);

  // checks if open fails or not
  if (numElem == -1) // fopen fails
    {
	  fprintf(stderr, "An error occured because fopen failed. \n");
      return EXIT_FAILURE;
    }

  // allocation of memory for the array 
  int * intArr;
  intArr = (int*) malloc(sizeof(int) * numElem);
  
  //checks wheter allocation is succesfull or not
  if(intArr == NULL)
  {
	fprintf(stderr, "An error occured because allocation was unsuccessful. \n");
    return EXIT_FAILURE; // if the allocation was unsuccessful, EXIT_FAILURE is returned
  }

  bool rtv = readInt(argv[1], intArr, numElem);

  if (rtv == false) // read fail
    {
	 fprintf(stderr, "An error occured because the array was unable to be read and copied. \n");
     return EXIT_FAILURE; 
    }
  
  // call qsort using the comparison function you write
  qsort(intArr, numElem, sizeof(int), compareInt);
  
  // write the sorted array to a file whose name is argv[2]
  
  rtv = writeInt(argv[2], intArr, numElem);
  if (rtv == false) // read fail
    {
	  fprintf(stderr, "An error occured because the file could not be written. \n");
      free(intArr); // frees space
      return EXIT_FAILURE;
    }

  free(intArr); //frees space
  
  return EXIT_SUCCESS;
}
#endif
