#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main( int argc, char *argv[] ) {
  char fileName[100];
  FILE *filep;

  // display syntax if no arguments passed on command line                     \
                                                                                
  if ( argc <= 1 ) {
    printf("Syntax: %s filename\n", argv[0] );
    return 1;
  }

  // if an argument is passed, it must be a file name                          \
                                                                                
  strcpy( fileName, argv[1] );

  filep = fopen(fileName,"r");
  if (filep == NULL){
          printf("File %s could not be opened!\n",fileName);
    return 1;
  }
  int dict = 10;
  int current =0;
  char * dictionary = malloc(dict*sizeof(char));

  int c;
  while (fscanf(filep, "%d", &c) != EOF) {
    if (c == 0) {
      int num;
      fscanf(filep, "%d", &num);

      if(current>=dict){
        dict *=2;
        dictionary = realloc(dictionary, dict*sizeof(char));
      }
      dictionary[current] = num;
      printf("%c", dictionary[current]);
      current++;
    }
    else {
      if (c>0 && c<=current){
        printf("%c", dictionary[c-1]);
      }
      else {
        printf("\nError: invalid dictionary index %d\n", c);}
    }
  }
  fclose(filep);
  free(dictionary);
  return 0;
}
