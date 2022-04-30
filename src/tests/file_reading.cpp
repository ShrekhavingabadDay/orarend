#include "../include/filereader.hpp"
#include "stream_overloading.hpp"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[]){

	FileReader fr;

	TimeTable tt = fr.parse_file(argv[1]);
/*
	for (Lesson lesson : lessons){
		lesson.sort_intervals();*/
	Lesson lesson = tt.get_random_lesson();
	cout << lesson.get_id() << " name: " << lesson.get_name() << " weekly_count: " << lesson.get_weekly_count() << endl;
	/*
		for (Interval ival : lesson.get_intervals()) {
			cout << ival << " ";
		}
		cout << endl;
	}
*/
	return 0;
}
