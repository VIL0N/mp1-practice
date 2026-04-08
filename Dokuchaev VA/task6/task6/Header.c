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

char* to_lower(char* arr2) {
    int j = 0;
    for (;arr2[j] != '\0';j++) {
        arr2[j] = tolower(arr2[j]);
    }
    return arr2;
}
char* asking() {
    char author[MAX_LEN] = { 0 };
    printf("\nWhich author's books are we looking for?\nIf you wanna ");
    printf(RED "END" RESET);
    printf(" write 'exit'\n");
    scanf_s("%s", author, MAX_LEN);
    return author;
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
        strcpy(book[b].publisher, token);
        token = strtok(NULL, ";");
        book[b].year = atoi(token);
    }

}
void print_books(BOOK* books, int kauthorbooks) {
    if (kauthorbooks <= 0 || books == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("Books of %s:\n\n", books[0]);

    for (int i = 0; i < kauthorbooks; i++) {
        printf("%s\n", books[i].fio);
        printf("%s\n", books[i].namebook);
        printf("%s\n", books[i].publisher);
        printf("%d\n\n", books[i].year);  
    }
}
BOOK* search(BOOK* book, int n, char* author, int * kauthorbooks) {
    char buffer[MAX_LEN];
    BOOK* books;
     int i = 0;    
     int j = 0;
     strcpy(buffer, author);
     to_lower(buffer);
     for (;i < n; i++) {
        char buffer2[MAX_LEN];  
        strcpy(buffer2, book[i].fio);
        to_lower(buffer2);
        if (strstr(buffer2, buffer)!=NULL) {
            (*kauthorbooks)++;
        }
     }

     books = alloc_library((*kauthorbooks));
     i = 0;
     for (;i < n; i++) {
         char buffer2[MAX_LEN];
         strcpy(buffer2, book[i].fio);
         to_lower(buffer2);
         if (strstr(buffer2, buffer) != NULL) {
             strcpy(books[j].fio, book[i].fio);
             strcpy(books[j].namebook, book[i].namebook);
             strcpy(books[j].publisher, book[i].publisher);
             books[j].year = book[i].year;
             j++;
         }
     }
     return books;
}

