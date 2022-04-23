#include "../include/filereader.hpp"
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char *argv[]){

	FileReader fr;

	vector<Lesson> lessons = fr.parse_file(argv[1]);

	for (Lesson lesson : lessons){
		std::cout << "name: " << lesson.get_name() << "\nstart: " << lesson.get_intervals()[0].get_start() << std::endl;
	}

	return 0;
}
