#ifndef INCLUDE_TIC_TAC_TOE_TIC_TAC_TOE_HPP
#define INCLUDE_TIC_TAC_TOE_TIC_TAC_TOE_HPP

#include <algorithm>
#include <exception>

#include <boost/numeric/ublas/matrix.hpp>

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

	std::ostream& operator<<(std::ostream& stream, player to_output)
	{
		switch(to_output)
		{
			case player::one:
				stream << "Player One";
				break;
			case player::two:
				stream << "Player Two";
				break;
			case player::none:
				stream << "No Player";
				break;
			case player::unknown:
				stream << "Unknown Player";
				break;
		}
		return stream;
	}

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

			player winner() const noexcept
			{
				auto column_winner =
					check_for_winner(
						column_begin(grid),
						column_end(grid));
				if(column_winner != player::none)
				{
					return column_winner;
				}

				auto row_winner = 
					check_for_winner(
						row_begin(grid),
						row_end(grid));
				if(row_winner != player::none)
				{
					return row_winner;
				}

				auto diagonal_winner = check_for_diagonal_winner();
				if(diagonal_winner != player::none)
				{
					return diagonal_winner;
				}

				return player::unknown;
			}

			auto width() const
			{
				return grid.size1();
			}

			auto height() const
			{
				return grid.size2();
			}

			field& operator()(size_type x, size_type y)
			{
				return grid(x, y);
			}
			const field& operator()(size_type x, size_type y) const
			{
				return grid(x, y);
			}

			auto begin1()
			{
				return grid.begin1();
			}
			auto end1()
			{
				return grid.end1();
			}

			auto begin1() const
			{
				return grid.begin1();
			}
			auto end1() const
			{
				return grid.end1();
			}


			auto cbegin1() const
			{
				return grid.cbegin1();
			}
			auto cend1() const
			{
				return grid.cend1();
			}



			auto rbegin1()
			{
				return grid.rbegin1();
			}
			auto rend1()
			{
				return grid.rend1();
			}

			auto rbegin1() const
			{
				return grid.rbegin1();
			}
			auto rend1() const
			{
				return grid.rend1();
			}


			auto rcbegin1() const
			{
				return grid.rcbegin1();
			}
			auto rcend1() const
			{
				return grid.rcend1();
			}


			auto begin2()
			{
				return grid.begin2();
			}
			auto end2()
			{
				return grid.end2();
			}

			auto begin2() const
			{
				return grid.begin2();
			}
			auto end2() const
			{
				return grid.end2();
			}


			auto cbegin2() const
			{
				return grid.cbegin2();
			}
			auto cend2() const
			{
				return grid.cend2();
			}



			auto rbegin2()
			{
				return grid.rbegin2();
			}
			auto rend2()
			{
				return grid.rend2();
			}

			auto rbegin2() const
			{
				return grid.rbegin2();
			}
			auto rend2() const
			{
				return grid.rend2();
			}


			auto rcbegin2() const
			{
				return grid.rcbegin1();
			}
			auto rcend2() const
			{
				return grid.rcend2();
			}


		private:

			player top_right_to_bottom_left_winner() const noexcept
			{
				auto& first_field = grid(width() - 1,0);
				if(first_field.owner() != player::none)
				{
					auto x = width() -1;
					auto y = size_type{};
					for(
						;
						x >= 0 && y < height();
						--x, ++y)
					{
						if(first_field.owner() != grid(x,y).owner())
						{
							return player::none;
						}
					}
				}
				return first_field.owner();
			}
			player top_left_to_bottom_right_winner() const noexcept
			{
				auto& first_field = grid(0,0);
				if(first_field.owner() != player::none)
				{
					auto x = size_type{};
					auto y = size_type{};
					for(
						;
						x < width() && y < height();
						++x, ++y)
					{
						if(first_field.owner() != grid(x,y).owner())
						{
							return player::none;
						}
					}
				}
				return first_field.owner();
			}

			player check_for_diagonal_winner() const noexcept
			{
				auto winner = top_left_to_bottom_right_winner();
				if(winner != player::none)
				{
					return winner;
				}
				winner = top_right_to_bottom_left_winner();
				if(winner != player::none)
				{
					return winner;
				}
				return player::none;
			}

			template<
				typename Iterator1,
				typename Iterator2>
			player check_for_winner(Iterator1 begin, Iterator2 end) const noexcept
			{
				for(
					auto iterator = begin;
					iterator != end;
					++iterator)
				{
					auto first_field = *iterator;
					if(
						!first_field.empty() && 
						std::all_of(
							std::begin(iterator), std::end(iterator),
							[&](const auto& field)
							{
								return field.owner() == first_field.owner();
							}))
					{
						return first_field.owner();
					}
				}
				return player::none;
			}
			Grid grid;
	};

	using game = basic_game<boost::numeric::ublas::matrix<field>>;

	std::ostream& operator<<(std::ostream& stream, const field& field)
	{
		switch(field.owner())
		{
			case player::one:
				stream << "X";
				break;
			case player::two:
				stream << "O";
				break;
			case player::none:
				stream << " ";
				break;
			default:
				std::cerr << "ERROR! FIELD HAS AN UNKNOWN OWNER ERROR!\n";
				std::exit(1);
		}

		return stream;
	}

	template<typename Grid>
	inline void print_top_delimiter(std::ostream& stream, const basic_game<Grid>& game)
	{
		stream << '+';
		for(
			auto i = typename Grid::size_type{};
			i < game.width();
			++i)
		{
			stream << '-';
		}
		stream << '+';
		stream << '\n';
	}
	template<typename Grid>
	inline std::ostream& operator<<(std::ostream& stream, const basic_game<Grid>& game)
	{
		print_top_delimiter(stream, game);

		for(
			auto row = row_begin(game);
			row != row_end(game);
			++row)
		{
			stream << '|';
			for(const auto& field : row)
			{
				stream << field;
			}
			stream << '|';
			stream << '\n';
		}

		print_top_delimiter(stream, game);
		return stream;
	}
} // namespace tic_tac_toe

#endif
