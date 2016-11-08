#include "grid.hpp"

namespace tic_tac_toe
{
	enum class player
	{
		one,
		two,
		none,
		unknown
	};
	class field
	{
		public:
			bool empty() const;
			void fill();
	};

	template<typename Grid>
	class basic_game
	{
		public:
			using size_type = typename Grid::size_type;

			basic_game() : basic_game{3,3}
			{}
			basic_game(size_type width, size_type heigth) : grid{width,heigth}
			{}

			player winner();


			field& operator()(size_type x, size_type y)
			{
				return grid(x, y);
			}
			const field& operator()(size_type x, size_type y) const
			{
				return grid(x, y);
			}

		private:
			Grid grid;
	};

	using game = basic_game<grid<field>>;

	std::ostream& operator<<(std::ostream&, const game&);
} // namespace tic_tac_toe


