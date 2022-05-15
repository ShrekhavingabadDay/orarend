#include "../include/interval.hpp"
// #include "stream_overloading.hpp"

#include<iostream>

int main(int argc, char *argv[]) {
	Interval il = Interval("08:00-09:30");
	Interval il2 = Interval("06:20-10:50");
	Interval il3 = Interval("10:51-18:40");
	std::cout << "Interval1: " << il << std::endl;
	std::cout << "Interval2: " << il2 << std::endl;
	std::cout << "Interval1 == Interval2: " << (il==il2) << std::endl;
	std::cout << "Interval1 != Interval2: " << (il!=il2) << std::endl;
	std::cout << "il.overlaps(il2), il2.overlaps(il3)" << il.overlaps(il2) << il2.overlaps(il3) << std::endl;
	std::cout << "Interval3 > Interval1: " << (il3>il) << std::endl;
	return 0;
}
