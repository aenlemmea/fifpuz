#include <iostream>
#include <string>
#include <array>
#include "internal/tile.hh"

#if defined(__linux__)
	constexpr std::string clear = "\x1B[2J\x1B[H";
#endif
// BUG: Handle clear for windows.

class Board {
public:
	Board() {
		display_board();
	}

	/// Display the board with all the tiles.
	/// @returns void
	void display_board() {	
		std::cout << clear;
		for (auto i = 0; auto const& tile : solved_board) {
			std::cout << tile;
			i += 1;
			if (!(i % 4)) {
				std::cout << "\n";
			}
		}
	}
	
	friend class Controller;

private:
	
	bool slide_up() {
		return 0;
	}
	
	bool slide_down() {
		return 0;
	}
	
	bool slide_left() {
		return 0;
	}
	
	bool slide_right() {
		return 0;
	}

	void do_exit() {
		std::cout << "\n\nBYE\n\n";
		exit(0);
	}

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
