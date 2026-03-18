#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Header.h"

#define RED "\033[35m"
#define RESET "\033[0m"

int get_library_size(FILE* filename) {
    int a;
    fscanf_s(filename, "%d", &a);
    return a;
}

BOOK* alloc_library(int n) {
    BOOK* ptr = (BOOK*)malloc(n * sizeof(BOOK));
    return ptr;
}
BOOK** alloc_library2(int n) {
    BOOK** ptr = (BOOK**)calloc(n, sizeof(BOOK*)); // все элементы NULL
    return ptr;
}

char* to_lower(char* arr2) { // TODO
    int j = 0;
    for (;arr2[j] != '\0';j++) {
        arr2[j] = tolower(arr2[j]);
    }
    return arr2;
}

void read_library(BOOK* book, FILE* filep) {
    char buffer[MAX_LEN];
    char* token;
    int i = 0;
    int b = -1;
    fgets(buffer, MAX_LEN, filep);
    while (fgets(buffer, MAX_LEN, filep) != NULL) {
        b++;
        token = strtok(buffer, ";");
        if (token == NULL)
            break;
        strcpy(book[b].fio, token);
        token = strtok(NULL, ";");
        strcpy(book[b].namebook, token);
        token = strtok(NULL, ";");
        strcpy(book[b].izdatelb, token);
        token = strtok(NULL, ";");
        book[b].year = atoi(token);
    }

}
void print_books(BOOK** AuthorBooks, int kAuthorBooks) {
    if (kAuthorBooks <= 0 || AuthorBooks == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("Books of %s:\n\n", AuthorBooks[0]->fio);

    for (int i = 0; i < kAuthorBooks; i++) {
        printf(RED);
        printf("%s\n", AuthorBooks[i]->fio);
        printf("%s\n", AuthorBooks[i]->namebook);
        printf("%s\n", AuthorBooks[i]->izdatelb);
        printf("%d\n\n", AuthorBooks[i]->year);
        printf(RESET);
    }
}
void search(BOOK* book, int n, BOOK ** authorBooks, int* kAuthorBooks) { // TODO
    
    char author[MAX_LEN] = { 0 };
    while (strcmp(author, "exit") != 0) {
        char buffer[MAX_LEN];
        int i = 0;

        printf("\nWhich author's books are we looking for?\nIf you wanna ");
        printf(RED "END" RESET);
        printf(" write 'exit'\n");
        scanf_s("%s", author, MAX_LEN);        
        strcpy(buffer, author);
        to_lower(buffer);
        if (strcmp(buffer, "exit") == 0)
            break;
        (*kAuthorBooks) = 0;
        for (;i < n; i++) {
            char buffer2[MAX_LEN];  
            strcpy(buffer2, book[i].fio);
            to_lower(buffer2);
            if (strstr(buffer2, buffer)!=NULL) {
                authorBooks[(*kAuthorBooks)++] = &book[i];
            }
        }
        print_books(authorBooks, *kAuthorBooks);
    }
}

