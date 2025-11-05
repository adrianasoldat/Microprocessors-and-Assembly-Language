#include <stdio.h>
#include <string.h>


int main( int argc, char *argv[] ) {
  char fileName[100];
  FILE *filep;

  // display syntax if no arguments passed on command line                      
  if ( argc <= 1 ) {
    printf("Syntax: %s filename\n", argv[0] );
    return 1;
  }

  // if an argument is passed, it must be a file name                           
  strcpy( fileName, argv[1] );

  filep = fopen(fileName,"r");
  if (filep == NULL){
    printf("File %s could not be opened!\n",fileName);
    return 1;
  }
  char c;
  while (fscanf(filep, "%c", &c) != EOF) {
    if (c == 'g') {
      printf("gremlin");}
    else if (c == 'G') {
      printf("GREMLIN");}
    else {
      printf("%c", c);}
  }
  fclose(filep);
  return 0;
}
