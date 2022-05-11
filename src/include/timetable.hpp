#ifndef TIMETABLE
#define TIMETABLE

#define MAX_RETRIES 100

#include "interval_table.hpp"
#include "lesson.hpp"
#include <vector>

using std::vector;

class TimeTable : public IntervalTable<Lesson>
{
	private:
		const bool too_many (Lesson lesson, int col_num) const;
		bool insert_lesson( Lesson data, Interval interval, int col_num );	
	public:
		const bool generate(vector<Lesson> lessons);

};

#endif
