#include <string>
#include <iostream>
#include <ctype.h>
#include "header.h"
#include "fstream"
#include <sstream>

 AutoInfoLib::AutoInfoLib(std::ifstream &filename):autos(nullptr), datasize(0) {
    std::string first_line;
    if (!std::getline(filename, first_line)) return;
	datasize=std::stoi(first_line);
    autos = new AutoInfo[datasize];
}

 AutoInfoLib::~AutoInfoLib() {
     delete [] autos;
 }
 AutoInfoLib& AutoInfoLib::operator=(const AutoInfoLib&a) {
     if (this == &a) {
         return *this;
     }
     datasize = a.datasize;
     delete [] autos;
     autos = new AutoInfo[a.datasize];
     for (int i = 0; i < datasize; i++) {
         autos[i] = a.autos[i];
     }
     return *this;
 }
 AutoInfoLib::AutoInfoLib(const AutoInfoLib& a) {
     datasize = a.datasize;
     autos = new AutoInfo[datasize];

     for (int i = 0; i < datasize; i++) {
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
        db.getAutos()[i] = tmpAutoInfo;
        i++;
    }
}
AutoInfoLib::AutoInfoLib(int n) {
    datasize = n;
    autos = new AutoInfo[n];
}

AutoInfoLib AutoInfoLib::Search(const std::string& targetGibdd) const{
    int j = 0;
    for (int i = 0;i < datasize; i++) {
         if (autos[i].getGibddNumber() == targetGibdd) {
             j++;
         }
    }
    AutoInfoLib result(j);
    j = 0;
    for (int i = 0; i < datasize; i++) {
        if (autos[i].getGibddNumber() ==targetGibdd)
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