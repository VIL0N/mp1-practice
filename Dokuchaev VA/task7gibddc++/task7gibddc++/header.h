#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Fio {
	std::string Family;
	std::string Name;
	std::string Otchestvo;
	friend std::ostream& operator<<(std::ostream& os, const Fio& f) {
		os << f.Family << " " << f.Name << " " << f.Otchestvo;
		return os;
	}
};

struct Date {
	int day;
	int month;
	int year;
	friend std::ostream& operator<<(std::ostream& os, const Date& d) {
		os << d.day << " " << d.month << " " << d.year;
		return os;
	}
};

struct AutoInfo {
	Fio fio;
	Date date;
	std::string RegistrationNumberAuto;
	std::string PassportNumber;
	std::string PhoneNumber;
	std::string GibddNumber;
	friend std::ostream& operator<<(std::ostream &os, const AutoInfo& a) {
		os << a.date << " " << a.fio << " " << a.GibddNumber << " " << a.PassportNumber << " " << a.PhoneNumber << " " << a.RegistrationNumberAuto;
		return os;
	}
};

struct AutoInfoLib {
	AutoInfo* autos; 
	size_t data_size;
	AutoInfoLib() : autos(nullptr), data_size(0) {}
	AutoInfoLib(std::ifstream& filename);
	AutoInfoLib(int);
	~AutoInfoLib();
	AutoInfoLib(const AutoInfoLib&);
	AutoInfoLib Search(const std::string& targetGibdd) const;
	friend std::ostream& operator<<(std::ostream& os, const AutoInfoLib& a) {
		os << a.autos;
		return os;
	}
	AutoInfoLib& operator=(const AutoInfoLib&);
};

void read_data(std::ifstream& filen, AutoInfoLib& db);

#endif // __HEADER_H
