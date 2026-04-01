#ifndef __HEADER_H
#define __HEADER_H
#define MAXLEN 256
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	char Fio[MAXLEN];
	char Date_Birth[MAXLEN];
	char Registration_Number_Auto[MAXLEN];
	char Passport_Number[MAXLEN];
	char Phone_Number[MAXLEN];
	char Gibdd_Number[MAXLEN];

} LIB;
int get_data_size(FILE* filename);

LIB* alloclib(int n);
LIB** allocalloclib(int n);

void read_data(FILE* filename, int n, LIB* data);

void to_lower(char* arr1);
void finderr(int n, LIB* datebase, LIB** fdatebase, int* k_needle);
void print_gibdd_number(int k_needle, LIB** fdatebase);

#endif __HEADER_H
