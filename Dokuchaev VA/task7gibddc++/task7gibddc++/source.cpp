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
	std::ifstream filen(argv[1]);
	AutoInfoLib db(filen);
	read_data(filen, db);
	std::string target = asking();
	AutoInfoLib persons=db.Search(target);
	print_gibdd_number(persons);
	return 0;
}