#include <string>
#include <iostream>
#include <ctype.h>
#include "header.h"
#include "fstream"
#include <sstream>

PersonsLib::~PersonsLib() {
    delete[] persons;
};
PersonsLib::PersonsLib(int i) {
    count = i;
    persons = new Fio[i];
};

bool Date::IsValid(int d, int m, int y) {
    if (d < 0 || d>31 || m < 0 || m>12 || y < 0 || y>3000) {
        return 0;
    };
    int daysinmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
        daysinmonth[1] += 1;
    };

    if (d < daysinmonth[m]) {
        return 1;
    }
    else {
        return 0;
    }
};

Date::Date(int d, int m, int y) {
    if (IsValid(d, m, y) == 0) {
        throw std::invalid_argument("invalid_argument");
    };
    day = d;
    month = m;
    year = y;
};
Date::Date() {
    day = 0;
    month = 0;
    year = 0;
};
AutoInfo::AutoInfo() {
    std::string x = " ";
    fio.setFamily(x);
    fio.setName(x);
    fio.setLastname(x);
    date.setDay(0);
    date.setMonth(0);
    date.setYear(0);
    setRegistrationNumber(x);
    setPassportNumber(x);
    setPhoneNumber(x);
    setGibddNumber(x);
};

AutoInfoLib::AutoInfoLib(std::string& filename) : autos(nullptr), datasize(0) {
    std::ifstream filen(filename);
    std::string first_line;
    if (!std::getline(filen, first_line)) return;
    datasize = std::stoi(first_line);
    autos = new AutoInfo[datasize];
    std::string buffer;
    std::getline(filen, buffer);
    int i = 0;
    while (std::getline(filen, buffer)) {
        AutoInfo tmpAutoInfo;
        std::stringstream s(buffer);
        std::string element;
        std::getline(s, element, ';');
        tmpAutoInfo.getFio().setFamily(element);
        std::getline(s, element, ';');
        tmpAutoInfo.getFio().setName(element);
        std::getline(s, element, ';');
        tmpAutoInfo.getFio().setLastname(element);
        std::getline(s, element, ';');
        tmpAutoInfo.getDate().setDay(element);
        std::getline(s, element, ';');
        tmpAutoInfo.getDate().setMonth(element);
        std::getline(s, element, ';');
        tmpAutoInfo.getDate().setYear(element);
        std::getline(s, element, ';');
        tmpAutoInfo.setRegistrationNumber(element);
        std::getline(s, element, ';');
        tmpAutoInfo.setPassportNumber(element);
        std::getline(s, element, ';');
        tmpAutoInfo.setPhoneNumber(element);
        std::getline(s, element, ';');
        tmpAutoInfo.setGibddNumber(element);
        autos[i] = tmpAutoInfo;
        i++;
    };
};

AutoInfoLib::~AutoInfoLib() {
    delete[] autos;
};

AutoInfoLib::AutoInfoLib(const AutoInfoLib& a) {
    datasize = a.datasize;
    autos = new AutoInfo[datasize];
    for (int i = 0; i < datasize; i++) {
        autos[i] = a.autos[i];
    };
};

AutoInfoLib::AutoInfoLib(int n) {
    datasize = n;
    autos = new AutoInfo[n];
};

const AutoInfoLib& AutoInfoLib::operator=(const AutoInfoLib& a) {
    if (this == &a) {
        return *this;
    };
    datasize = a.datasize;
    delete[] autos;
    for (int i = 0; i < datasize; i++) {
        autos[i] = a.autos[i];
    };
    return *this;
};

PersonsLib AutoInfoLib::Search(const std::string& targetGibdd) const {
    int j = 0;
    for (int i = 0;i < datasize; i++) {
        if (autos[i].getGibddNumber() == targetGibdd) {
            j++;
        };
    };
    PersonsLib result(j);
    j = 0;
    for (int i = 0; i < datasize; i++) {
        if (autos[i].getGibddNumber() == targetGibdd)
        {
            result.persons[j] = autos[i].getFio();
            j++;
        };
    };
    if (j == 0) {
        throw std::runtime_error("Nothing has been found");
    };
    return result;
};