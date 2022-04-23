#include "../include/interval.hpp"

#include<iostream>

int main(int argc, char *argv[]) {
	Interval il = Interval("08:00-09:30");
	std::cout << "start: " << il.get_start() << std::endl << "end: " << il.get_end() << std::endl;
	return 0;
}
