#include "auxiliary.h";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 256

char* asking() {
    char* answer[MAXLEN];
    printf("Please write gibdd Number\n");
    scanf("%s", answer);
    to_lower(answer);
    return answer;
}

void print_gibdd_number(PersonalInfo *persons) {
    int i = 0;
    for (; i < persons->count;i++) {
        printf("\n");
        printf("->Family %s\n", persons->autos[i].fio.Family);
        printf("->Name: %s\n", persons->autos[i].fio.Name);
        printf("->Otchestvo: %s\n", persons->autos[i].fio.Otchestvo);
        printf("->Number auto: %s\n", persons->autos[i].RegistrationNumberAuto);
		printf("->Gibdd number: %s\n", persons->autos[i].GibddNumber);
    }
}