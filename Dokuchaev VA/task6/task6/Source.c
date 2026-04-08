#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Header.h"
int main(int argc, char* argv[]) {
    int init_books_count;
    FILE* filep;
    BOOK* init_books_library;
    BOOK* found_books_library;
    char author[MAX_LEN];
    int kAuthorBooks = 0;
    if (argc <= 1) {
        printf("Error");
        return 1;
    }
    filep = fopen(argv[1], "r");
    if (filep == NULL) {
        fprintf(stderr, "Error OPEN\n");
        return 1;
    }

    init_books_count = get_library_size(filep);
    init_books_library = alloc_library(init_books_count);

    if (init_books_library == NULL) {
        fprintf(stderr, "Memory ERROR\n");
        fclose(filep);
        return 1;
    }

    read_library(init_books_library, filep);
    strcpy(author, asking());
    if (strcmp(author, "exit") == 0) {
        printf("Good bye!");
        fclose(filep);
        free(init_books_library);
        return 0;
    }
    found_books_library = search(init_books_library, init_books_count, author, &kAuthorBooks);
    print_books(found_books_library, kAuthorBooks);
    fclose(filep);
    free(found_books_library);
    free(init_books_library);
    return 0;
}
