#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Header.h"
int main(int argc, char* argv[]) { // argc, argv
    if (argc >= 1) {
        int n;
        FILE* filep = fopen(argv[1], "r");
        BOOK* book;
        BOOK* books;
        char author[MAX_LEN];
        int kAuthorBooks = 0;
        if (filep == NULL) {
            fprintf(stderr, "Error OPEN\n");
            return 1;
        }

        n = get_library_size(filep);
        book = alloc_library(n);

        if (book == NULL) {
            fprintf(stderr, "Memory ERROR\n");
            fclose(filep);
            return 1;
        }

        read_library(book, filep);
        strcpy(author, asking());
        if (strcmp(author, "exit") == 0) {
            printf("Good bye!");
            fclose(filep);
            free(book);
            return 0;
        }
        books = search(book, n, author, &kAuthorBooks);
        print_books(books, kAuthorBooks);
        fclose(filep);
        free(books);
        free(book);
    }
    else {
        printf("Error");
    }
    return 0;
}
