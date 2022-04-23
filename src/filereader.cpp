#include "include/filereader.hpp"

using std::string;
using std::vector;

vector<Lesson> FileReader::parse_file(const char *filename){

	vector<Lesson> lessons;

	std::ifstream file(filename);

	while(std::getline(file, line)) {

		std::istringstream iss(line);

		string lesson_name;
		int weekly_count;

		if(!(iss >> lesson_name >> weekly_count)) { break; } // TODO: hibkezelés

		vector<string> tokens;
		string token;
		while(std::getline(iss, token, '\t'))
			tokens.push_back(token);

		lessons.push_back(Lesson(lesson_name, weekly_count, tokens));

	}

	return lessons;
}
