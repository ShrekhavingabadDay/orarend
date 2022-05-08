#ifndef TIMETABLE
#define TIMETABLE

#define MAX_RETRIES

#include "interval_table.hpp"
#include "lesson.hpp"

class TimeTable : public IntervalTable<Lesson>
{
	protected:
		const bool too_many (Lesson lesson, int col_num) const;
	public:
		bool insert_data( Lesson data, Interval interval, int col_num );	

};

#endif
