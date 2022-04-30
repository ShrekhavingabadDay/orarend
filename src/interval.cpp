#include "include/interval.hpp"

#include<string>

using std::string;

Interval::Interval(string str){
	start = stoi(str.substr(0, 2))*60 + stoi(str.substr(3, 2));
	end = stoi(str.substr(6,2))*60 + stoi(str.substr(9,2));
}

Interval::Interval(int m_start, int m_end) 
	: start(m_start), end(m_end) {}

int Interval::get_start(void) const{
	return start;
}

int Interval::get_end(void) const {
	return end;
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

/*
Interval Interval::operator+(const Interval &other) const {
	int n_start = (this->get_start() < other.get_start()) ? this->get_start() : other.get_start();
	int n_end = (this->get_end() > other.get_end()) ? this->get_end() : other.get_end();
	return Interval(n_start, n_end);
}
*/
