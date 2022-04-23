#ifndef INTERVAL
#define INTERVAL

#include<string>

using std::string;

class Interval {
	private:
		int start, end;
	public:
		Interval(string interval_str);
		int get_start(void);
		int get_end(void);
};

#endif
