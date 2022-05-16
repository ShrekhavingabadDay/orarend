#ifndef INTERVAL_TABLE
#define INTERVAL_TABLE

#include "interval.hpp"
#include <vector>
#include <cstddef>
#include <algorithm>

template <typename T>
struct interval_table_elem {
	bool occupied;
	T *value;
	Interval interval;
};

using std::vector;

template <typename T>
class IntervalTable {
	protected:
		vector<vector<T*>> table;
		vector<Interval> intervals;
	public:

		IntervalTable<T>( int col_count, vector<Interval> interval_vector );

		IntervalTable<T>( int col_count, int row_count );

		~IntervalTable<T> ();

		// túlterheljük a kiirató operátort
		// ostream& opeartor<<(ostream& os, const Intervaltable<T>& intervaltable);

		// https://stackoverflow.com/questions/27431029/binary-search-with-returned-index-stl
		// https://cplusplus.com/reference/vector/vector/insert
		void insert_interval( Interval interval );

		bool insert_data( T data, Interval interval, int col_num );

		const int find_index( Interval interval ) const;
		const int get_col_num(void) const;
		const int get_row_num(void) const;

		const vector<Interval>& get_intervals(void) const;

		// https://stackoverflow.com/questions/6969881/operator-overload
		class Proxy {
			private:
				// https://stackoverflow.com/questions/9590265/invalid-use-of-non-static-data-member
				vector<T*> & vec;
				vector<Interval> & ivals;
			public:
				Proxy(vector<T*> & m_vec, vector<Interval> & m_ivals) : vec(m_vec), ivals(m_ivals) {}

				interval_table_elem<T> operator[](int index){
					T *val = vec[index];
					if (val != nullptr)
						return {
							true,
							val,
							ivals[index]
						};
					return {
						false,
						nullptr,
						ivals[index]
					};
				}
		};

		Proxy operator[] (int index) {
			return Proxy(table[index], intervals);
		};

		// docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
		friend ostream& operator<<(ostream& os, const IntervalTable<T>& intervaltable){
			int rows = intervaltable.get_row_num();
			for (int i = 0; i<rows; i++){
				os << intervaltable.intervals[i] << "|\t";
				for (auto col : intervaltable.table)
					os << col[i] << "|\t";
				os << '\n';
			}
			return os;
		}

		// friend függvények nem örklődnek, ezért készítünk örökölhető print függvényt is

		void print(void) const;

};


#endif
