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

struct PersonsLib {
	int count;
	Fio* persons;
	friend std::ostream& operator<<(std::ostream& os, const PersonsLib& f)
	{
		for (int i = 0; i < f.count; i++)
		{
			os << f.persons[i] << "\n";
		}
		return os;
	};
	PersonsLib(int);
	~PersonsLib();
};

struct Date {
	int day;
	int month;
	int year;
	bool IsValid(int, int, int);
	Date(int, int, int);
	Date();
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
	AutoInfo();
};

struct AutoInfoLib {
	AutoInfo* autos; 
	size_t data_size;
	AutoInfoLib() : autos(nullptr), data_size(0) {}
	AutoInfoLib(std::string& filename);
	AutoInfoLib(int);
	~AutoInfoLib();
	AutoInfoLib(const AutoInfoLib&);
	PersonsLib Search(const std::string& targetGibdd) const;
	friend std::ostream& operator<<(std::ostream& os, const AutoInfoLib& a) {
		os << a.autos;
		return os;
	}
	const AutoInfoLib& operator=(const AutoInfoLib&);
};

#endif // __HEADER_H
