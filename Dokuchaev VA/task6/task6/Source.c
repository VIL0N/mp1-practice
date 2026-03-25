#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Header.h"
int main() {
    FILE* filep = fopen("date.CSV", "r");
    if (filep == NULL) {
        fprintf(stderr, "Error OPEN\n");
        return 1;
    }

    int n = get_library_size(filep);
    BOOK* book = alloc_library(n);

    if (book == NULL) {
        fprintf(stderr, "Memory ERROR\n");
        fclose(filep);
        return 1;
    }

    read_library(book, filep);

    for (int i = 0; i < n; i++) {
        printf("FIO: %s\n", book[i].fio);
        printf("Name of book: %s\n", book[i].namebook);
        printf("Izdatelb: %s\n", book[i].izdatelb);
        printf("Year: %d\n", book[i].year);
        printf("\n");
    }
    BOOK** authorbook = alloc_library2(n);
    int kAuthorBooks=0;
    search(book, n, authorbook, &kAuthorBooks);
    fclose(filep);
    free(authorbook);
    free(book);
    printf("BYE-BYE");
    return 0;
}
