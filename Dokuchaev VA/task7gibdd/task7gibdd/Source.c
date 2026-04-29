#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 256
#include <ctype.h>
#include "header.h"
#include "auxiliary.h"


int main(int argc, char *argv[]) {
	FILE* filep = NULL;
	AutoInfo* found_database = NULL;
	char* target = NULL;
	GibddDB fautos;
	PersonalInfo persons;
	int found_count;
	if (argc <1) {
		printf("Wrong number of arguments");
		return 1;
	}
	filep = fopen(argv[1], "r");
	fautos.data_size = get_data_size(filep);
	fautos.autos = alloclib(fautos.data_size);
	read_data(filep, &fautos);
	found_database = NULL;
	target = asking();
	search_registration_number_auto(&fautos, &persons, target);
	print_gibdd_number(&persons);
	//print_gibdd_number(found_count, found_database);
	free(persons.autos);
	free(fautos.autos);
	return 0;
}