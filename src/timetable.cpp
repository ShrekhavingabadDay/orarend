#include "include/timetable.hpp"
#include "include/lesson.hpp"

const bool TimeTable::too_many (Lesson lesson, int col_num) const {
	int id = lesson.get_id();
	return true;
}

bool TimeTable::insert_data( Lesson lesson, Interval interval, int col_num ){

	if (too_many(lesson, col_num)) return false;

	table[col_num][find_index(interval)] = &lesson;
	return true;

}

