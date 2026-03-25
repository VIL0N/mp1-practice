#ifndef __HEADER_H
#define __HEADER_H
#define MAXLEN 64
typedef struct {
	char Fio[MAXLEN];
	char Date_Birth[MAXLEN];
	char Registration_Number_Auto[MAXLEN];
	char Passport_Number[MAXLEN];
	char Phone_Number[MAXLEN];
	int  Gibdd_Number[MAXLEN];

} LIB;
int get_data_size(FILE* filename);

void read_data(FILE* filename, int n, LIB* data);

void to_lower(char* arr1);

void print_gibdd_number();




#endif __HEADER_H
