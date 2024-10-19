#ifndef TILE_HH
#define TILE_HH

#include <ostream>
#include <string>

template <typename T = int>
class Tile {
public:
	Tile(T val) : value(val) {
	}

	bool isEmpty() const noexcept {
		if (value == static_cast<T>(0)) {
			return true;
		}
		return false;
	}

	T getNum() const noexcept {
		return value;
	}

	friend std::ostream& operator<<( std::ostream& stream, const Tile& tile) {
		return stream << " " <<  (tile.isEmpty() ? " " : std::to_string(tile.value)) << "  ";
	}

	private:
		T value;
};
#endif
