#include <iostream>

#include "tic_tac_toe.hpp"

int main()
{
	auto game = tic_tac_toe::game{};

	while(game.winner() == tic_tac_toe::player::unknown)
	{
		std::cout << game.current_player()  << " make your move:\n";

		auto x = tic_tac_toe::game::size_type{};
		auto y = tic_tac_toe::game::size_type{};
		std::cin >> x >> y;
		
		auto& field = game(x,y);
		if(field.empty())
		{
			field.occupy();
		}
		else
		{
			std::cerr << "The field (" << x << '|' << y << ") is occupied\n"
				        << "Please pick another field.\n";
		}

		std::cout << game;
	}

	std::cout << game.winner() << " has won the game!\n";
}
