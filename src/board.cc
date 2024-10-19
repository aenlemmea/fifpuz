#include <iostream>
#include <iterator>
#include <string>
#include <array>
#include <algorithm>

#include "internal/tile.hh"
#include "internal/point.hh"

#if defined(__linux__)
	constexpr std::string clear = "\x1B[2J\x1B[H";
#endif
// BUG: Handle clear for windows.

class Board {
public:
	Board() {
		display_board();
	}
	
	/**
	 * @return The location of the empty tile in the 4 * 4 grid of tiles.
	 */
	inline Point empty_at() {
		auto it = std::find(board.begin(), board.end(), Tile{0});
		std::size_t dist = std::distance(board.begin(), it);
		short x = dist % 4;
		short y = dist / 4;
		return Point(x, y);
	}

	/// Display the board with all the tiles.
	/// @returns void
	void display_board() {	
		std::cout << clear;
		for (auto i = 0; auto const& tile : board) {
			std::cout << tile;
			i += 1;
			if (!(i % 4)) {
				std::cout << "\n";
			}
		}
	}
	
	friend class Controller;

private:

	std::array<Tile<int>, 16> board = {
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
