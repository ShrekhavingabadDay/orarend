#ifndef LESSON
#define LESSON

#include<string>
#include<vector>
#include<iostream>

#include "interval.hpp"
#include "random_integer.hpp"

using std::vector;
using std::string;
using std::ostream;

class Lesson {

private:
	const RandInt RNG;
	const int id;
	string name;
	int weekly_count;
	vector<Interval> intervals;

public:
	Lesson(string m_name, int m_weekly_count, vector<Interval> m_intervals, int id);
	void set_weekly_count(int m_weekly_count);
	void set_name(string m_name);
	void set_intervals(vector<Interval> m_intervals);
	string get_name(void) const;
	vector<Interval> get_intervals(void) const;
	int get_weekly_count(void) const;
	void sort_intervals(void);
	int get_id(void) const; 
	Interval get_random_interval(void) const;
	friend ostream& operator<<(ostream& os, const Lesson& lesson);
};

#endif
