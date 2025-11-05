#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Syntax: %s filename\n", argv[0]);
        return 1;
    }

    FILE *filep = fopen(argv[1], "r");
    if (filep == NULL) {
        fprintf(stderr, "File %s could not be opened!\n", argv[1]);
        return 1;
    }

    /* dynamic array of char* */
    size_t dict_cap = 16;
    size_t dict_len = 0; 
    char **dictionary = malloc(dict_cap * sizeof(char *));
    

    int code;
    while (fscanf(filep, "%d", &code) == 1) {
        if (code == 0) {
            int ascii;
            if (fscanf(filep, "%d", &ascii) != 1) {
                fprintf(stderr, "Unexpected EOF while reading ascii value after 0\n");
                break;
            }

            char *entry = malloc(2);
            
            entry[0] = (char)ascii;
            entry[1] = '\0';

            if (dict_len + 1 > dict_cap) {
                dict_cap *= 2;
                char **tmp = realloc(dictionary, dict_cap * sizeof(char *));
                
                dictionary = tmp;
            }

            dictionary[dict_len] = entry;
            dict_len++;

            fputs(entry, stdout);
        } else { 
            if (code <= 0 || (size_t)code > dict_len) {
                fprintf(stderr, "\nError: invalid dictionary index %d\n", code);
                int maybe_ascii;
                
                continue;
            }

            int ascii;
            if (fscanf(filep, "%d", &ascii) != 1) {
                fprintf(stderr, "Unexpected EOF while reading ascii value after index %d\n", code);
                break;
            }

            char *src = dictionary[code - 1]; 
            size_t src_len = strlen(src);

            char *entry = malloc(src_len + 2);
            

            memcpy(entry, src, src_len);
            entry[src_len] = (char)ascii;
            entry[src_len + 1] = '\0';

            if (dict_len + 1 > dict_cap) {
                dict_cap *= 2;
                char **tmp = realloc(dictionary, dict_cap * sizeof(char *));
                
                dictionary = tmp;
            }

            dictionary[dict_len] = entry;
            dict_len++;

            fputs(entry, stdout);
        }
    }

    for (size_t i = 0; i < dict_len; ++i) {
        free(dictionary[i]);
    }
    free(dictionary);
    fclose(filep);

    return 0;
}
