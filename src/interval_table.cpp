#include "include/interval_table.hpp"

using std::vector;

template <typename T>
IntervalTable<T>::IntervalTable( int col_count, vector<Interval> interval_vector ) {

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

	table.resize(col_count);
	for (auto & col : table) {
		col.resize(row_count);
		for (auto & elem : col)
			elem = nullptr;
	}

}

// https://stackoverflow.com/questions/27431029/binary-search-with-returned-index-stl
// https://cplusplus.com/reference/vector/vector/insert
template <typename T>
bool IntervalTable<T>::insert_interval( Interval interval ) {
	auto it = std::lower_bound(intervals.begin(), intervals.end(), interval);
	if (it == intervals.end() || *it != interval)
		return false;
	intervals.insert(it, interval);
	return true;
}

template <typename T>
bool IntervalTable<T>::insert_data( T data, Interval interval, int col_num ) {
	int index = find_index(interval);
	if (index == -1) return false;
	table[col_num][index] = *data;
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

