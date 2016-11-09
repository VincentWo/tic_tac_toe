#include <exception>

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

	class basic_game_base
	{
		public:
			basic_game_base() : current_player_{player::one}
			{}
			player current_player() noexcept
			{
				return current_player_;
			}
			void next_player() noexcept
			{
				if(current_player_ == player::one)
				{
					current_player_ = player::two;
				}
				else
				{
					current_player_ = player::one;
				}
			}
		private:
			player current_player_;
	};

	class field
	{
		public:
			explicit field(basic_game_base& game_base) : game_base{game_base}
			{}

			bool empty() const noexcept
			{
				return owner() == player::none;
			}
			player owner() const noexcept
			{
				return owner_;
			}
			void occupy()
			{
				if(!empty())
				{
					throw already_occupied{};
				}
				owner_ = game_base.current_player();
				game_base.next_player();
			}

			class already_occupied : public std::exception
			{
				public:
					const char* what() const noexcept override 
					{
						return "Tried to occupy an occupied field!";
					}
			};
		private:
			player owner_ = player::none;
			basic_game_base& game_base;
	};


	template<typename Grid>
	class basic_game : public basic_game_base
	{
		public:
			using size_type = typename Grid::size_type;

			basic_game() : basic_game{3,3}
			{}
			basic_game(size_type width, size_type heigth)
				:	basic_game_base{},
					grid{width,heigth, field{*this}}
			{}

			player winner() noexcept;


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


