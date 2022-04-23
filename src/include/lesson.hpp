#ifndef LESSON
#define LESSON

#include<string>
#include<vector>

using std::vector;
using std::string;

class Lesson {

private:
		string name;
		int weekly_count;
		vector<string> intervals;

public:
	Lesson(string m_name, int m_weekly_count, vector<string> m_intervals);
	void set_weekly_count(int m_weekly_count);
	void set_name(string m_name);
	void set_intervals(vector<string> m_intervals);
	string get_name(void);
	vector<string> get_intervals(void);
};

#endif
