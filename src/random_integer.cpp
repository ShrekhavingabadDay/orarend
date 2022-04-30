#include "include/random_integer.hpp"
#include <stdlib.h>
#include <time.h>

RandInt::RandInt(unsigned int m_range) : range(m_range) {
	srand(time(NULL));
}

unsigned int RandInt::gen(void) const {
	return rand() % range +1;
}
