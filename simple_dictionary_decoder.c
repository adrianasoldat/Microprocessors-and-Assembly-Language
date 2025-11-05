//This program implements a simplified dictionary decoder in C. Unlike a function-based decoder, it reads input directly from the console. The program:

//Reads the first integer as the dictionary size (N) and dynamically allocates an array of N characters.

//Reads the next N integers as ASCII codes to populate the dictionary.

//Reads another integer as the size of the data (M) to be decompressed.
//It then uses this dictionary to decompress the input and write the decompressed output.


#include <stdio.h>
#include <stdlib.h>

int main () {
  int n;
  scanf("%d", &n);
  char *c_ptr;
  c_ptr	= malloc(n*sizeof(char));

  for (int i=0; i<n;i++){
    int code;
    scanf("%d", &code);
    char c = code;
    c_ptr[i] = c;
  }

  int m;
  scanf("%d",&m);
  int *data;
  data = malloc(m*sizeof(int));

  for (int i=0;i<m; i++){
    scanf("%d",&data[i]);
  }
  
  int ind;
  for (int i=0;i<m; i++){
    ind =data[i];
    printf("%c",c_ptr[ind]);
  }


  free(c_ptr);
  free(data);
  return 0;
}
