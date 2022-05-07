#ifndef INTERVAL
#define INTERVAL

#include<string>

using std::string;

class Interval {
	private:
		int start, end;
		string display_string;
	public:
		
		// konstruktorok
		Interval(string interval_str);
		Interval(int m_start, int m_end);

		// getterek
		const int& get_start(void) const;
		const int& get_end(void) const;
		const string& get_display_string(void) const;

		bool overlaps(const Interval &other) const;

		// operátor túlterhelések
		Interval operator+(const Interval &other) const;
		bool operator==(const Interval &other) const;
		bool operator!=(const Interval &other) const;
		bool operator>(const Interval &other) const;
		bool operator<(const Interval &other) const;
};

#endif
