#include "include/timetable.hpp"
#include "include/lesson.hpp"
#include "include/random_integer.hpp"
#include <vector>

using std::vector;

TimeTable::TimeTable(vector<Lesson> m_lessons) 
	: lessons(m_lessons), RNG(m_lessons.size()-1) {}

Lesson TimeTable::get_random_lesson(void) const {
	return lessons[RNG.gen()];
}
