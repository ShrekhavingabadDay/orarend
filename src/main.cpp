#include "include/timetable.hpp"
#include "include/filereader.hpp"
#include <vector>
#include <iostream>

typedef enum {
	HETFO,
	KEDD,
	SZERDA,
	CSUTORTOK,
	PENTEK,
} e_nap;

int main(int argc, char *argv[]) {

	// összesen hat óra lesz max. egy napon
	vector<Interval> ora_idopontok {
		Interval("08:00-08:45"),
		Interval("09:00-09:45"),
		Interval("10:00-10:45"),
		Interval("11:00-11:45"),
		Interval("12:00-12:45"),
		Interval("13:00-13:45"),
	};

	// beolvassuk az órákat filereaderrel
	FileReader fr(argv[1]);
	vector<Lesson> lessons = fr.parse_file();

	// öt napból álló órarend
	TimeTable tt(PENTEK+1, ora_idopontok);

	tt.generate(lessons);

	return 0;
}
