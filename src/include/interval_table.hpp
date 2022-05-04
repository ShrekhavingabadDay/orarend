#ifndef INTERVAL_TABLE
#define INTERVAl_TABLE

#include "interval.hpp"
#include <vector>
#include <cstddef>
#include <bits/stdc++.h>

template <typename T>
struct interval_table_elem {
	bool occupied;
	T *value;
	Interval interval;
};

using std::vector;

template <typename T>
class IntervalTable {
	private:
		vector<vector<T*>> table;
		vector<Interval> intervals;
	public:
		
		IntervalTable( int col_count, vector<Interval> interval_vector );

		IntervalTable( int col_count, int row_count );

		// https://stackoverflow.com/questions/27431029/binary-search-with-returned-index-stl
		// https://cplusplus.com/reference/vector/vector/insert
		bool insert_interval( Interval interval );

		bool insert_data( T data, Interval interval, int col_num = 0 );

		const int find_index( Interval interval ) const;

		// https://stackoverflow.com/questions/6969881/operator-overload
		class Proxy {
			private:
				vector<T*> vec;
			public:
				Proxy(vector<T*> m_vec) : vec(m_vec) {}

				const interval_table_elem<T> operator[](int index) const{
					T *val = vec[index];
					if (val != nullptr)
						return {
							true,
							val,
							intervals[index]
						};
					return {
						false,
						nullptr,
						intervals[index]
					};
				}
		};

		const Proxy operator[] (int index) const {
			return Proxy(table[index]);
		};
};


#endif
