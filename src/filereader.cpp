#include "include/filereader.hpp"
#include "include/lesson.hpp"
#include "include/interval.hpp"
#include "include/timetable.hpp"

#include<iostream>

using std::string;
using std::vector;

vector<Lesson> FileReader::parse_file(const char *filename){

	vector<Lesson> lessons;

	std::ifstream file(filename);

	int i = 0;
	while(std::getline(file, line)) {

		std::istringstream iss(line);

		string lesson_name;
		int weekly_count;

		if(!(iss >> lesson_name >> weekly_count)) { break; } // TODO: hibakezelés

		string token;
		vector<Interval> intervals;
		std::getline(iss, token, '\t');
		while(std::getline(iss, token, '\t'))
			intervals.push_back(Interval(token));

		lessons.push_back(Lesson(lesson_name, weekly_count, intervals, i));
		i++;

	}

	return lessons;
}
