#include <string>
#include <iostream>
#include <ctype.h>
#include "header.h"
#include "fstream"
#include <sstream>

 AutoInfoLib::AutoInfoLib(std::ifstream &filename):autos(nullptr), data_size(0) {
    std::string first_line;
    if (!std::getline(filename, first_line)) return;
	data_size=std::stoi(first_line);
    autos = new AutoInfo[data_size];
}

 AutoInfoLib::~AutoInfoLib() {
     delete [] autos;
 }
 AutoInfoLib& AutoInfoLib::operator=(const AutoInfoLib&a) {
     if (this == &a) {
         return *this;
     }
     data_size = a.data_size;
     delete [] autos;
     for (int i = 0; i < data_size; i++) {
         autos[i] = a.autos[i];
     }
     return *this;
 }
 AutoInfoLib::AutoInfoLib(const AutoInfoLib& a) {
     data_size = a.data_size;
     autos = new AutoInfo[data_size];

     for (int i = 0; i < data_size; i++) {
         autos[i] = a.autos[i];
     }
 }

void read_data(std::ifstream& filen, AutoInfoLib& db) {
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
        db.autos[i] = tmpAutoInfo;
        i++;
    }
}
AutoInfoLib::AutoInfoLib(int n) {
    data_size = n;
    autos = new AutoInfo[n];
}

AutoInfoLib AutoInfoLib::Search(const std::string& targetGibdd) const{
    int j = 0;
    for (int i = 0;i < data_size; i++) {
         if (autos[i].GibddNumber == targetGibdd) {
             j++;
         }
    }
    AutoInfoLib result(j);
    j = 0;
    for (int i = 0; i < data_size; i++) {
        if (autos[i].GibddNumber==targetGibdd)
        {
            result.autos[j] = autos[i];
            j++;
        }
    }
    if (j == 0) {
        throw std::runtime_error("Nothing has been found");
    }
    return result;
}