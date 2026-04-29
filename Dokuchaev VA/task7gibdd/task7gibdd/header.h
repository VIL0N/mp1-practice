#ifndef __HEADER_H
#define __HEADER_H
#define MAXLEN 256
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char Family[MAXLEN];
	char Name[MAXLEN];
	char Otchestvo[MAXLEN];
} Fio;

typedef struct {
	char day[5];
	char month[5];
	char year[5];
} Date;

typedef struct {
	Fio fio; 
	Date date; 
	char RegistrationNumberAuto[MAXLEN];
	char PassportNumber[MAXLEN];
	char PhoneNumber[MAXLEN];
	char GibddNumber[MAXLEN];
} AutoInfo;

typedef struct {
	AutoInfo* autos;
	int data_size;
} GibddDB;

typedef struct {
	AutoInfo* autos;
	int count;
} PersonalInfo;

AutoInfo* alloclib(int size); 
void read_data(FILE* filename, GibddDB* db);
int get_data_size(FILE* filename);
void to_lower(char* arr1);
void search_registration_number_auto(GibddDB* db, PersonalInfo* persons, char* target);

#endif __HEADER_H
