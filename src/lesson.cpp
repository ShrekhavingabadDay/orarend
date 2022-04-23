#include<string>
#include<vector>
#include "include/lesson.hpp"
#include "include/interval.hpp"

using std::vector;
using std::string;


Lesson::Lesson(string m_name, int m_weekly_count, vector<Interval> m_intervals){
	name = m_name;
	weekly_count = m_weekly_count;
	intervals = m_intervals;
}

void Lesson::set_weekly_count(int m_weekly_count) {
	weekly_count = m_weekly_count;
}
void Lesson::set_name(string m_name){
	name = m_name;
}
void Lesson::set_intervals(vector<Interval> m_intervals) {
	intervals = m_intervals;
}

string Lesson::get_name(void) {
	return name;
}
vector<Interval> Lesson::get_intervals(void){
	return intervals;
}
