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

LIB* alloclib(int n) {
    LIB* ptr = (LIB*)malloc(n * sizeof(LIB));
    return ptr;
}

LIB** allocalloclib(int n) {
    LIB** ptr = (LIB**)malloc(n *sizeof(LIB*));
    return ptr;
}

void read_data(FILE* filename, int n, LIB* data) {
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
        strcpy(data[i].Fio, token);
        token = strtok(NULL, ";");
        strcpy(data[i].Date_Birth, token);
        token = strtok(NULL, ";");
        strcpy(data[i].Registration_Number_Auto, token);
        token = strtok(NULL, ";");
        strcpy(data[i].Passport_Number, token);
        token = strtok(NULL, ";");
        strcpy(data[i].Phone_Number, token);
        token = strtok(NULL, ";");
        strcpy(data[i].Gibdd_Number, token);
    }

}

void to_lower(char* arr1) {
    int j = 0;
    for (;arr1[j] != '\0';j++) {
        arr1[j] = tolower(arr1[j]);
    }
}

void print_gibdd_number(int k_needle, LIB** fdatebase) {
    int i = 0;
    for (; i < k_needle;i++) {
        printf("->Date_Birth %s\n", fdatebase[i]->Date_Birth);
        printf("->Fio %s\n", fdatebase[i]->Fio);
        printf("->Gibdd_Number %s", fdatebase[i]->Gibdd_Number);
        printf("->Passport_Number %s\n", fdatebase[i]->Passport_Number);
        printf("->Phone_Number %s\n", fdatebase[i]->Phone_Number);
        printf("->Registration_Number_Auto %s\n", fdatebase[i]->Registration_Number_Auto);
    }
}

void finderr(int n, LIB * datebase, LIB** fdatebase, int* k_needle) {
    char  target[MAXLEN] = {0};
    while((strcmp(target, "END")!=NULL)) {
        char  target[MAXLEN];
        printf("Please write Registration Number Auto. If you wanna go out write END\n");
        scanf_s("%s", target, MAXLEN);
        if (strcmp(target, "END") == NULL) {
            break;
        }
        int i = 0;
        (*k_needle) = 0;
        for (;i < n;i++) {
            char buffer2[MAXLEN];
            to_lower(target);
            strcpy(buffer2, datebase[i].Registration_Number_Auto);
            to_lower(buffer2);
            if (strstr(buffer2, target) != NULL) {
                fdatebase[(*k_needle)++] = &datebase[i];
            }
        }
        if ((*k_needle) == 0) {
            printf("Nothing\n");
        }
        print_gibdd_number(*k_needle, fdatebase);
    }
}
