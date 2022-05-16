#include "include/timetable.hpp"
#include "include/lesson.hpp"
#include "include/interval.hpp"

using std::vector;

TimeTable::TimeTable(int col_num, vector<Interval> intervals)
	:IntervalTable{col_num, intervals}
{
}

void TimeTable::clear(void) {
	for (auto col : table)
		for (auto row : col)
			row = nullptr;
}

const bool TimeTable::too_many (Lesson in_lesson) const {
	int comp_id = in_lesson.get_id();
	int weekly_max = in_lesson.get_weekly_count();

	int counter = 0;
	for (auto col : table){
		for (Lesson* lesson : col){
			if (lesson != nullptr && comp_id == lesson->get_id())
				counter++;
			if (counter == weekly_max)
				return true;
		}
	}

	return false;
}

const bool TimeTable::insert_lesson( Lesson lesson, Interval interval, int col_num ){

	if (too_many(lesson)) return false;

	int index = find_index(interval);
	if (index == -1) return false;
	table[col_num][index] = new Lesson(lesson);
	return true;
}

const void TimeTable::generate(vector<Lesson> lessons) {
	for (int iterations = 0; iterations < 100; iterations++){
	clear();
	for (int i=0; i<get_col_num(); i++){
		for (auto lesson : lessons) {
			// a szám itt bármi lehet
			Interval interval = lesson.get_random_interval();
			for (int k = 0; k<20; k++){
				if (!( (*this)[i][find_index(interval)].occupied )) break;
				Interval interval = lesson.get_random_interval();
			}
			insert_lesson(lesson, interval, i);
		}
	}
	print();
	}
	
}
