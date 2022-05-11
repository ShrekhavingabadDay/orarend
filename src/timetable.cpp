#include "include/timetable.hpp"
#include "include/lesson.hpp"

using std::vector;

const bool TimeTable::too_many (Lesson lesson, int col_num) const {
	int comp_id = lesson.get_id();
	int weekly_max = lesson.get_weekly_count();

	int counter = 0;
	for (auto lesson : table[col_num]){
		if (comp_id == lesson->get_id())
			counter++;
		if (counter == weekly_max)
			return true;
	}

	return false;
}

bool TimeTable::insert_lesson( Lesson lesson, Interval interval, int col_num ){

	if (too_many(lesson, col_num)) return false;

	// https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function
	return IntervalTable<Lesson>::insert_data(lesson, interval, col_num);

}

