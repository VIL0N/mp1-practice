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
        daysinmonth[1]+=1;
    };

    if (d < daysinmonth[m]) {
        return 1;
    }
    else {
        return 0;
    }
}
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
}

AutoInfo::AutoInfo() {
    fio.Family = "NoN";
    fio.Name = "NoN";
    fio.Otchestvo = "NoN";
    date.day = 0;
    date.month = 0;
    date.year = 0;
    RegistrationNumberAuto= "NoN";
    PassportNumber = "NoN";
    PhoneNumber = "NoN";
    GibddNumber = "NoN";
}
AutoInfoLib::AutoInfoLib(std::string& filename): autos(nullptr), data_size(0) {
    std::ifstream filen(filename);
    std::string first_line;
    if (!std::getline(filen, first_line)) return;
    data_size = std::stoi(first_line);
    autos = new AutoInfo[data_size];
    std::string buffer;
    std::getline(filen, buffer);
    int i = 0;
    while (std::getline(filen, buffer)) {
        AutoInfo tmpAutoInfo;
        std::stringstream s(buffer);
        std::string element;
        std::getline(s, element, ';');
        tmpAutoInfo.fio.Family = element;
        std::getline(s, element, ';');
        tmpAutoInfo.fio.Name = element;
        std::getline(s, element, ';');
        tmpAutoInfo.fio.Otchestvo = element;
        std::getline(s, element, ';');
        tmpAutoInfo.date.day = stoi(element);
        std::getline(s, element, ';');
        tmpAutoInfo.date.month = stoi(element);
        std::getline(s, element, ';');
        tmpAutoInfo.date.year = stoi(element);
        std::getline(s, element, ';');
        tmpAutoInfo.RegistrationNumberAuto = element;
        std::getline(s, element, ';');
        tmpAutoInfo.PassportNumber = element;
        std::getline(s, element, ';');
        tmpAutoInfo.PhoneNumber = element;
        std::getline(s, element, ';');
        tmpAutoInfo.GibddNumber = element;
        autos[i] = tmpAutoInfo;
        i++;
    }
}
AutoInfoLib::~AutoInfoLib() {
     delete [] autos;
 }
AutoInfoLib::AutoInfoLib(const AutoInfoLib& a) {
    data_size = a.data_size;
    autos = new AutoInfo[data_size];
     for (int i = 0; i < data_size; i++) {
        autos[i] = a.autos[i];
     }
}
AutoInfoLib::AutoInfoLib(int n) {
    data_size = n;
    autos = new AutoInfo[n];
}
const AutoInfoLib& AutoInfoLib::operator=(const AutoInfoLib& a) {
    if (this == &a) {
        return *this;
    }
    data_size = a.data_size;
    delete[] autos;
    for (int i = 0; i < data_size; i++) {
        autos[i] = a.autos[i];
    }
    return *this;
}
PersonsLib AutoInfoLib::Search(const std::string& targetGibdd) const {
    int j = 0;
    for (int i = 0;i < data_size; i++) {
        if (autos[i].GibddNumber == targetGibdd) {
            j++;
        }
    }
    PersonsLib result(j);
    j = 0;
    for (int i = 0; i < data_size; i++) {
        if (autos[i].GibddNumber == targetGibdd)
        {
            result.persons[j] = autos[i].fio;
            j++;
        }
    }
    if (j == 0) {
        throw std::runtime_error("Nothing has been found");
    }
    return result;
}
