#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

class Fio {
	std::string family;
	std::string name;
	std::string lastname;
	friend std::ostream& operator<<(std::ostream& os, const Fio& f) {
		os << f.family << " " << f.name << " " << f.lastname;
		return os;
	}
public:
	void setFamily(std::string& n) { family = n; };
	void setName(std::string& n) { name = n; };
	void setLastname(std::string& n) { lastname = n; };
	const std::string& getFamily() const { return family; };
	const std::string& getName() const { return name; };
	const std::string& getLastname() const { return lastname; };
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
	public:
	PersonsLib(int);
	~PersonsLib();
};

class Date {
	int day;
	int month;
	int year;
	friend std::ostream& operator<<(std::ostream& os, const Date& d) {
		os << d.day << " " << d.month << " " << d.year;
		return os;
	}
public:
	bool IsValid(int, int, int);
	Date(int, int, int);
	Date();
	void setDay(std::string& n) { day = stoi(n); };
	void setMonth(std::string& n) { month = stoi(n); };
	void setYear(std::string& n) { year = stoi(n); };

	void setDay(int n) { day = n; };
	void setMonth(int n) { month = n ; };
	void setYear(int n) { year = n; };

	int& getDay() { return day; };
	int& getMonth() { return month; };
	int& getYear() { return year; };
};

class AutoInfo {
	Fio fio;
	Date date;
	std::string RegistrationNumber;
	std::string PassportNumber;
	std::string PhoneNumber;
	std::string GibddNumber;
public:
	friend std::ostream& operator<<(std::ostream &os, const AutoInfo& a) {
		os << a.date << " " << a.fio << " " << a.GibddNumber << " " << a.PassportNumber << " " << a.PhoneNumber << " " << a.RegistrationNumber;
		return os;
	}
	AutoInfo();
	Fio& getFio() { return fio; };
	Date& getDate() { return date; };
	std::string& getRegistrationNumber() { return RegistrationNumber; };
	std::string& getPassportNumber() { return PassportNumber; };
	std::string& getPhoneNumber() { return PhoneNumber; };
	std::string& getGibddNumber() { return GibddNumber; };
	void setRegistrationNumber(std::string&n) { RegistrationNumber=n; };
	void setPassportNumber(std::string& n) { PassportNumber=n; };
	void setPhoneNumber(std::string& n) { PhoneNumber=n; };
	void setGibddNumber(std::string& n) { GibddNumber=n; };
};

class AutoInfoLib {
private:
	AutoInfo* autos;
	int datasize;
public:
	AutoInfoLib() : autos(nullptr), datasize(0) {}
	AutoInfoLib(std::string& filename);
	AutoInfoLib(int);
	~AutoInfoLib();
	AutoInfoLib(const AutoInfoLib&);
	PersonsLib Search(const std::string& targetGibdd) const;
	friend std::ostream& operator<<(std::ostream& os, const AutoInfoLib& a) {
		for (int i = 0; i < a.datasize; i++) {
			os << a.autos[i] << "\n";
		}
		return os;
	}
	const AutoInfoLib& operator=(const AutoInfoLib&);
	AutoInfo* getAutos() { return autos; };
	int& getDatasize() { return datasize; };
};

#endif // __HEADER_H
