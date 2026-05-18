#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLEN 256
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int get_data_size(FILE* filename) {
    int a;
    fscanf_s(filename, "%d", &a);
    return a;
}

AutoInfo* alloclib(int size) {
    AutoInfo* ptr = (AutoInfo*)malloc(size * sizeof(AutoInfo));
    return ptr;
}

void read_data(FILE* filename, GibddDB* db){
    char buffer[MAXLEN];
    char* token;
    int i = -1;
    fgets(buffer, MAXLEN, filename);
    fgets(buffer, MAXLEN, filename);
    while (fgets(buffer, MAXLEN, filename) != NULL) {
        i++;
        token = strtok(buffer, ";");
        if (token==NULL)
            break;
        strcpy(db->autos[i].fio.Name, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].fio.Family, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].fio.Otchestvo, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].date.day, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].date.month, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].date.year, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].RegistrationNumberAuto, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].PassportNumber, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].PhoneNumber, token);
        token = strtok(NULL, ";");
        strcpy(db->autos[i].GibddNumber, token);
    }
}

void to_lower(char* arr1) {
    int j = 0;
    for (;arr1[j] != '\0';j++) {
        arr1[j] = tolower(arr1[j]);
    }
}

void search_registration_number_auto(GibddDB *db, PersonalInfo *persons, char* target) {
    int i = 0;
    int j = -1;
    char buffer[MAXLEN];
    persons->count = 0
    for (;i < db->data_size; i++) {
        strcpy(buffer, db->autos[i].GibddNumber);
        //to_lower(buffer);
        if (strcmp(buffer, target) == 0) {
            (persons->count)++;
        }
    }
    persons->autos = alloclib(persons->count);
    i = 0;
    for (;i < db->data_size; i++) {
        strcpy(buffer, db->autos[i].GibddNumber);
        //to_lower(buffer);
        if (strcmp(buffer, target) == 0) {
            j++;
            strcpy(persons->autos[j].date.day, db->autos[i].date.day);
            strcpy(persons->autos[j].date.month, db->autos[i].date.month);
            strcpy(persons->autos[j].date.year, db->autos[i].date.year);

            strcpy(persons->autos[j].fio.Family, db->autos[i].fio.Family);
            strcpy(persons->autos[j].fio.Name, db->autos[i].fio.Name);
            strcpy(persons->autos[j].fio.Otchestvo, db->autos[i].fio.Otchestvo);

            strcpy(persons->autos[j].GibddNumber, db->autos[i].GibddNumber);
            strcpy(persons->autos[j].PassportNumber, db->autos[i].PassportNumber);
            strcpy(persons->autos[j].PhoneNumber, db->autos[i].PhoneNumber);
            strcpy(persons->autos[j].RegistrationNumberAuto, db->autos[i].RegistrationNumberAuto);
        }
    }
}
