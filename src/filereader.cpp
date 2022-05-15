#include "include/filereader.hpp"
#include "include/lesson.hpp"
#include "include/interval.hpp"

#include<stdlib.h>

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using std::string;
using std::vector;

FileReader::FileReader(const char *filename){
	file = std::ifstream(filename);
	if (!file.good())
		std::cout << filename << " nem létezik!\nAdjon meg új fájlnevet: ";
	else
		return;

	string new_filename;
	std::cin >> new_filename;
	file = std::ifstream(new_filename.c_str());

	while(!file.good()){
		std::cout << new_filename << " nem létezik!\nAdjon meg új fájlnevet: ";
		std::cin >> new_filename;
		file = std::ifstream(new_filename.c_str());
	};
};

vector<Lesson> FileReader::parse_file(void){

	vector<Lesson> lessons;

	string line;

	int i = 0;
	while(std::getline(file, line)) {

		std::istringstream iss(line);

		string lesson_name;
		int weekly_count;

		if(!(iss >> lesson_name >> weekly_count)){
			std::cout << "A megadott bemeneti fájl nem megfelelő adatokat tartalmaz, vagy nem megfelelő formátumban tartalmazza őket!" << std::endl;
			exit(1);
		}

		string token;
		vector<Interval> intervals;
		std::getline(iss, token, '\t');
		while(std::getline(iss, token, '\t')){
			intervals.push_back(Interval(token));
		}

		lessons.push_back(Lesson(lesson_name, weekly_count, intervals, i));
		i++;

	}

	return lessons;
}
