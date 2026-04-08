#ifndef __HEADER_H
#define __HEADER_H

#define MAX_LEN 256

typedef struct {
    char fio[MAX_LEN];
    char namebook[MAX_LEN];
    char publisher[MAX_LEN];
    int year;
}BOOK;

char* to_lower(char* arr2);

BOOK* alloc_library(int n);
char* asking();
int get_library_size(FILE* filename);
void read_library(BOOK* book, FILE* filep);
BOOK* search(BOOK* book, int n, char* author, int* kauthorbooks);
void print_books(BOOK* AuthorBooks, int kAuthorBooks);

#endif