#include "auxiliary.h"
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {
	if (argc < 1) {
		std::cout << "Wrong";
		return 1;
	}
	std::string targett = argv[1];

	try {
		AutoInfoLib db(targett);
		std::string target = asking();
		PersonsLib persons = db.Search(target);
		std::cout << persons;
	}
	catch (...) {
		std::cout << "error";
	}

	return 0;
}