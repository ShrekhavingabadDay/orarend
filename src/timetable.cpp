#include "include/timetable.hpp"
#include "include/lesson.hpp"
#include "include/interval.hpp"

using std::vector;

TimeTable::TimeTable(int col_num, vector<Interval> intervals)
	:IntervalTable{col_num, intervals}
{
}

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

const bool TimeTable::insert_lesson( Lesson lesson, Interval interval, int col_num ){

	if (too_many(lesson, col_num)) return false;

	// https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function
	return IntervalTable<Lesson>::insert_data(lesson, interval, col_num);

}

const void TimeTable::generate(vector<Lesson> lessons) {
	for (int i=0; i<get_col_num(); i++)
		for (auto lesson : lessons) 
			// MAX_RETRIES definiálva a hedörben
			for (int j = 0; j<MAX_RETRIES; j++){
				Interval interval = lesson.get_random_interval(); 
				insert_lesson(lesson, interval, i);
			}
	
}
