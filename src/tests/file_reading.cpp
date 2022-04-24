#include "../include/filereader.hpp"
#include "stream_overloading.hpp"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[]){

	FileReader fr;

	vector<Lesson> lessons = fr.parse_file(argv[1]);

	for (Lesson lesson : lessons){
		lesson.sort_intervals();
		cout << "name: " << lesson.get_name() << " weekly_count: " << lesson.get_weekly_count() << endl;
		for (Interval ival : lesson.get_intervals()) {
			cout << ival << " ";
		}
		cout << endl;
	}

	return 0;
}
