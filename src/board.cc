#include <iostream>
#include <string>
#include <array>
#include "internal/tile.hh"

constexpr std::string clear = "\x1B[2J\x1B[H";

class Board {
public:
	Board() {
		display_solved();
	}

	void display_solved() {	
		std::cout << clear;
		for (auto const& tile : solved_board) {
			std::cout << tile;
		}
	}
private:
	std::array<Tile<int>, 16> solved_board = {
		Tile{1},
		Tile{2},
		Tile{3},
		Tile{4},
		Tile{5},
		Tile{6},
		Tile{7},
		Tile{8},
		Tile{9},
		Tile{10},
		Tile{11},
		Tile{12},
		Tile{13},
		Tile{14},
		Tile{15},
		Tile{0},
	};
};
