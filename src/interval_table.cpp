#include "include/interval_table.hpp"
#include "include/lesson.hpp"
#include <algorithm>
#include <string>
using std::vector;

template <typename T>
IntervalTable<T>::IntervalTable( int col_count, vector<Interval> interval_vector ) {

	intervals = interval_vector;
	std::sort(intervals.begin(), intervals.end());
	int rows = interval_vector.size();

	table.resize(col_count);
	for (auto & col : table) {
		col.resize(rows);
		for (auto & elem : col)
			elem = nullptr;
	}

}

template <typename T>
IntervalTable<T>::IntervalTable( int col_count, int row_count ) {

	intervals.reserve(row_count);

	table.resize(col_count);
	for (auto & col : table) {
		col.resize(row_count);
		for (auto & elem : col)
			elem = nullptr;
	}

}

template <typename T>
IntervalTable<T>::~IntervalTable() {
	for (auto vec : table)
		for (auto elem : vec)
			delete elem;
}

// bináris keresés hatékonyabb volna
// https://cplusplus.com/reference/vector/vector/insert
template <typename T>
void IntervalTable<T>::insert_interval( Interval interval ) {

	if (intervals.empty()) {
		intervals.insert(intervals.begin(), interval);
		return;
	}

	auto it = intervals.begin();
	for (; it != intervals.end(); ++it)
		if (*it > interval)
			break;

	intervals.insert(it, interval);

}

template <typename T>
bool IntervalTable<T>::insert_data( T data, Interval interval, int col_num ) {
	int index = find_index(interval);
	if (index == -1) return false;
	table[col_num][index] = new T(data);
	return true;
}

template <typename T>
const int IntervalTable<T>::find_index( Interval interval ) const{
	// https://stackoverflow.com/questions/27431029/binary-search-with-returned-index-stl
	auto it = std::lower_bound(intervals.begin(), intervals.end(), interval);
	if (it == intervals.end() || *it != interval)
		return -1;
	std::size_t index = std::distance(intervals.begin(), it);
	return index;
}

template <typename T>
const int IntervalTable<T>::get_col_num( void ) const {
	return table.size();
}

template <typename T>
const int IntervalTable<T>::get_row_num( void ) const {
	return intervals.size();
}

template <typename T>
const vector<Interval>& IntervalTable<T>::get_intervals(void) const {
	return intervals;
}

// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class IntervalTable<int>;
template class IntervalTable<Lesson>;
template class IntervalTable<std::string>;
