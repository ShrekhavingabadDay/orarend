#include "include/interval_table.hpp"
#include "include/lesson.hpp"
#include <algorithm>
#include <string>
#include <iostream>

using std::vector;

// konstruktor 1: 
template <typename T>
IntervalTable<T>::IntervalTable( int col_count, vector<Interval> interval_vector ) {

	intervals = interval_vector;
	// rendezzük a vektort
	// mondhatod hogy mondjuk innen nézted:
	// https://www.tutorialspoint.com/sorting-a-vector-in-cplusplus
	std::sort(intervals.begin(), intervals.end());
	// size függvény megmondja, hogy milyen hosszú a vektor
	int rows = interval_vector.size();

	// https://www.cplusplus.com/reference/vector/vector/resize/
	// felgyorsítja az elemek hozzàadàsàt a vektorhoz/
	// auto-t nemtom tanultàtok-e
	// automatikusan beállítja a változó típusát
	table.resize(col_count);
	for (auto col : table) {
		col.resize(rows);
		for (auto elem : col)
			elem = nullptr;
	}

}

template <typename T>
IntervalTable<T>::IntervalTable( int col_count, int row_count ) {
	// https://www.cplusplus.com/reference/vector/vector/reserve
	intervals.reserve(row_count);

	table.resize(col_count);
	for (auto & col : table) {
		col.resize(row_count);
		for (auto & elem : col)
			elem = nullptr;
	}

}

// mivel pointereket tárolunk, ezért konstruktorban fel is szabadíttyuk őket nagybao
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
	// mivel rendezett a vektor, ezért bináris kereséssel keressük meg az intervallumot
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

template <typename T>
void IntervalTable<T>::print(void) const {
	int rows = get_row_num();
	for (int i = 0; i<rows; i++){
		std::cout << i << '\t' << intervals[i] << "|\t";
		for (auto col : table){
			T* data = col[i];
			if (data != nullptr)
				std::cout << *(col[i]);
			std::cout << "|\t";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
}

// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class IntervalTable<int>;
template class IntervalTable<Lesson>;
template class IntervalTable<std::string>;
