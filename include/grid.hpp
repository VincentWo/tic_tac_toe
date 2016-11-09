#ifndef INCLUDE_TIC_TAC_TOE_GRID_HPP
#define INCLUDE_TIC_TAC_TOE_GRID_HPP
#include <cstddef>

template<typename Field>
class grid
{
	public:
		using size_type = std::size_t;

		grid(size_type width, size_type heigth);

		Field& operator()(size_type x, size_type y);
		const Field& operator()(size_type x, size_type y) const;
};

#endif
