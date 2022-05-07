#include<iostream>
#include<vector>
#include "../include/interval.hpp"

std::ostream& operator<<(std::ostream& stream, const Interval &other)
{
        stream << other.get_display_string();
        return stream;
}

std::ostream& operator<<(std::ostream& stream, const std::vector<Interval> &other)
{
	for (int i = 0; i<other.size()-1; i++)
		stream << other[i] << "; ";
	stream << other[other.size()-1];
	return stream;
}
