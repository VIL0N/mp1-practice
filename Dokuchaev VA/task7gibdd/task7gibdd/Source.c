#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 256
#include <ctype.h>
#include "header.h"


void main() {
	int n = 0;
	FILE* filep = fopen("DataGibdd.CSV", "r");
	n = get_data_size(filep);
	LIB* database = alloclib(n);
	printf("%d", n);
	read_data(filep, n, database);
	for (int i = 0; i < n; i++) {
		printf("%s\n", database[i].Fio);
	}
	LIB** f_datebase = allocalloclib(n);
	int k_needle = 0;
	finderr(n, database, f_datebase, &k_needle);
	print_gibdd_number(k_needle, f_datebase);
	free(database);
	free(f_datebase);
}