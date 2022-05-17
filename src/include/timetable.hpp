#ifndef TIMETABLE
#define TIMETABLE

#include "interval_table.hpp"
#include "lesson.hpp"
#include <vector>

using std::vector;

class TimeTable : public IntervalTable<Lesson>
{
	private:
		const bool too_many (Lesson lesson) const;
		const bool insert_lesson( Lesson data, Interval interval, int col_num );	
		void clear(void);
	public:
		TimeTable(int col_num, vector<Interval> intervals);
		const void generate(vector<Lesson> lessons);
};

#endif
