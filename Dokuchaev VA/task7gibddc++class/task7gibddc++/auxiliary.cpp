#include "auxiliary.h";
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

std::string asking() {
    std::string answer;
    printf("Please write gibdd Number\n");
    std::cin >> answer;
    return answer;
};