#ifndef TIMETABLE
#define TIMETABLE

#include "lesson.hpp"
#include "random_integer.hpp"
#include <vector>

using std::vector;

class TimeTable {

private:
	const vector<Lesson> lessons;
	const RandInt RNG;

public:
	TimeTable(vector<Lesson> lessons);
	Lesson get_random_lesson(void) const;

};

#endif
