#include "../include/filereader.hpp"
#include <iostream>
#include <vector>

using std::vector;

int main(int argc, char *argv[]){

	FileReader fr;

	vector<Lesson> lessons = fr.parse_file(argv[1]);

	for (Lesson lesson : lessons){
		std::cout << lesson.get_name() << std::endl;
	}

	return 0;
}
