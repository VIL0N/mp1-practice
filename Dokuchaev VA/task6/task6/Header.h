#ifndef __HEADER_H
#define __HEADER_H

#define MAX_LEN 256

typedef struct {
    char fio[MAX_LEN];
    char namebook[MAX_LEN];
    char izdatelb[MAX_LEN];
    int year;
}BOOK;

char* to_lower(char* arr2);
int get_library_size(FILE* filename);
BOOK* alloc_library(int n);
BOOK** alloc_library2(int n);
void read_library(BOOK* book, FILE* filep);
void search(BOOK* book, int n, BOOK* authorBooks, int* kAuthorBooks);
void print_books(BOOK AuthorBooks, int kAuthorBooks);

#endif