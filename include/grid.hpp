#ifndef INCLUDE_TIC_TAC_TOE_GRID_HPP
#define INCLUDE_TIC_TAC_TOE_GRID_HPP
#include <cstddef>


template<typename Field>
class grid
{
	public:
		using size_type = std::size_t;

		grid(size_type width, size_type heigth, const Field& default_field = Field{});

		Field& operator()(size_type x, size_type y);
		const Field& operator()(size_type x, size_type y) const;

		class column_iterator{};
		class column_const_iterator{};
		class column_reverse_iterator{};
		class column_const_reverse_iterator{};
		class row_iterator{};
		class row_const_iterator{};
		class row_reverse_iterator{};
		class row_const_reverse_iterator{};

		column_iterator begin1();
		column_iterator end1();
		column_const_iterator begin1() const;
		column_const_iterator end1() const;
		column_const_iterator cbegin1() const;
		column_const_iterator cend1() const;


		column_reverse_iterator rbegin1();
		column_reverse_iterator rend1();
		column_const_reverse_iterator rbegin1() const;
		column_const_reverse_iterator rend1() const;
		column_const_reverse_iterator crbegin1() const;
		column_const_reverse_iterator crend1() const;

		column_iterator column_begin();
		column_const_iterator column_begin() const;
		column_const_iterator column_cbegin() const;

		column_reverse_iterator column_rbegin();
		column_const_reverse_iterator column_rbegin() const;
		column_const_reverse_iterator column_crbegin() const;

		row_iterator begin2();
		row_const_iterator begin2() const;
		row_const_iterator cbegin2() const;

		row_reverse_iterator rbegin2();
		row_const_reverse_iterator rbegin2() const;
		row_const_reverse_iterator crbegin2() const;

		row_iterator row_begin();
		row_const_iterator row_begin() const;
		row_const_iterator row_cbegin() const;

		row_reverse_iterator row_rbegin();
		row_const_reverse_iterator row_rbegin() const;
		row_const_reverse_iterator row_crbegin() const;

		column_iterator column_end();
		column_const_iterator column_end() const;
		column_const_iterator column_cend() const;

		column_reverse_iterator column_rend();
		column_const_reverse_iterator column_rend() const;
		column_const_reverse_iterator column_crend() const;

		row_iterator end2();
		row_const_iterator end2() const;
		row_const_iterator cend2() const;

		row_reverse_iterator rend2();
		row_const_reverse_iterator rend2() const;
		row_const_reverse_iterator crend2() const;

		row_iterator row_end();
		row_const_iterator row_end() const;
		row_const_iterator row_cend() const;

		row_reverse_iterator row_rend();
		row_const_reverse_iterator row_rend() const;
		row_const_reverse_iterator row_crend() const;

};

template<typename Grid>
auto column_begin(Grid& grid)
{
	return grid.begin1();
}
template<typename Grid>
auto column_end(Grid& grid)
{
	return grid.end1();
}

template<typename Grid>
auto column_cbegin(const Grid& grid)
{
	return grid.cbegin1();
}
template<typename Grid>
auto column_cend(const Grid& grid)
{
	return grid.cend1();
}


template<typename Grid>
auto column_rbegin(const Grid& grid)
{
	return grid.rebegin1();
}
template<typename Grid>
auto column_rend(const Grid& grid)
{
	return grid.rend1();
}

template<typename Grid>
auto column_rcbegin(const Grid& grid)
{
	return grid.rcbegin1();
}
template<typename Grid>
auto column_rcend(const Grid& grid)
{
	return grid.rcend1();
}
	
template<typename Grid>
auto row_begin(Grid& grid)
{
	return grid.begin2();
}
template<typename Grid>
auto row_end(Grid& grid)
{
	return grid.end2();
}

template<typename Grid>
auto row_cbegin(const Grid& grid)
{
	return grid.cbegin2();
}
template<typename Grid>
auto row_cend(const Grid& grid)
{
	return grid.cend2();
}


template<typename Grid>
auto row_rbegin(const Grid& grid)
{
	return grid.rebegin2();
}
template<typename Grid>
auto row_rend(const Grid& grid)
{
	return grid.rend2();
}

template<typename Grid>
auto row_rcbegin(const Grid& grid)
{
	return grid.rcbegin2();
}
template<typename Grid>
auto row_rcend(const Grid& grid)
{
	return grid.rcend2();
}

#endif
