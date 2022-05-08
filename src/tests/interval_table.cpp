#include "../include/interval_table.hpp"
#include "../include/interval.hpp"
#include "stream_overloading.hpp"

typedef enum {
	HETFO,
	KEDD,
	SZERDA,
	CSUTORTOK,
	PENTEK,
	SZOMBAT,
	VASARNAP
} NAP;

using std::cout;
using std::endl;

int main(void) {

	IntervalTable<int> intervaltable(5,7);

	Interval elso_ora("08:00-09:30");
	Interval masodik_ora("09:50-10:00");
	Interval harmadik_ora("10:15-10:15");
	Interval negyedik_ora("12:45-13:15");
	Interval otodik_ora("13:25-15:15");

	intervaltable.insert_interval(masodik_ora);
	intervaltable.insert_interval(elso_ora);
	intervaltable.insert_interval(otodik_ora);
	intervaltable.insert_interval(harmadik_ora);
	intervaltable.insert_interval(negyedik_ora);

	std::cout << intervaltable.get_intervals() << std::endl;

	intervaltable.insert_data(5, elso_ora, 0);

	cout << *(intervaltable[0][intervaltable.find_index(elso_ora)].value) << endl;

	return 0;
}
