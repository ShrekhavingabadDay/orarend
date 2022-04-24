#ifndef INTERVAL
#define INTERVAL

#include<string>

using std::string;

class Interval {
	private:
		int start, end;
	public:
		
		// konstruktorok
		Interval(string interval_str);
		Interval(int m_start, int m_end);

		// getterek
		int get_start(void) const;
		int get_end(void) const;

		bool contains(const Interval &other) const;

		// operátor túlterhelések
		Interval operator+(const Interval &other) const;
		bool operator==(const Interval &other) const;
		bool operator!=(const Interval &other) const;
		bool operator>(const Interval &other) const;
		bool operator<(const Interval &other) const;
};

#endif
