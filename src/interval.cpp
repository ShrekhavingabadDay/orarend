#include "include/interval.hpp"

#include<string>

using std::string;

Interval::Interval(string str){
	start = stoi(str.substr(0, 2))*60 + stoi(str.substr(3, 2));
	end = stoi(str.substr(6,2))*60 + stoi(str.substr(9,2));
}

int Interval::get_start(void) {
	return start;
}

int Interval::get_end(void) {
	return end;
}
