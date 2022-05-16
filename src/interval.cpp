#include "include/interval.hpp"

#include<string>
#include<iostream>
#include<stdlib.h>
#include<exception>

using std::string;
using std::to_string;
using std::ostream;

Interval::Interval(string str) {
	try{
		start = stoi(str.substr(0, 2))*60 + stoi(str.substr(3, 2));
		end = stoi(str.substr(6,2))*60 + stoi(str.substr(9,2));
	}catch(std::exception &err){
		std::cout << str << " - Nem megfelelő formátumú intervallum!" << std::endl;
		exit(1);
	}
	std::cout << "epic" << std::endl;
	display_string = str;
}

Interval::Interval(int m_start, int m_end) 
	: start(m_start), end(m_end) {

	display_string = to_string(start/60) + ":" + to_string(start-start/60) + "-" + to_string(end/60) + to_string(end-end/60);

}

const int& Interval::get_start(void) const{
	return start;
}

const int& Interval::get_end(void) const {
	return end;
}

const string& Interval::get_display_string(void) const {
	return display_string;
}

bool Interval::operator==(const Interval &other) const {
	return ( this->get_start() == other.get_start() ) && ( this->get_end() == other.get_end() );
}

bool Interval::operator!=(const Interval &other) const {
	return !( *this == other );
}

bool Interval::operator>(const Interval &other) const {
	return (this->get_start() > other.get_start());
}

bool Interval::operator<(const Interval &other) const {
	return (this->get_start() < other.get_start());
}

bool Interval::overlaps(const Interval &other) const {
	return !( this->get_start() > other.get_end() || this->get_end() < other.get_start() );
}

ostream& operator<<(ostream& os, const Interval& interval){
	os << interval.get_display_string();
	return os;
}

/*
Interval Interval::operator+(const Interval &other) const {
	int n_start = (this->get_start() < other.get_start()) ? this->get_start() : other.get_start();
	int n_end = (this->get_end() > other.get_end()) ? this->get_end() : other.get_end();
	return Interval(n_start, n_end);
}
*/
