#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int get_data_size(FILE* filename) {
	int n = getc(filename);
	return n;
}

void read_data(FILE* filename, int n, LIB* data);

void to_lower(char* arr1);

void print_gibdd_number();