#ifndef TILE_HH
#define TILE_HH

#include <ostream>

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

	bool operator==(const Tile& tile) const {
		return value == tile.value;
	}

	friend std::ostream& operator<<( std::ostream& stream, const Tile& tile) {
		//	return stream << " " <<  (tile.isEmpty() ? " " : std::to_string(tile.value)) << "  ";
		// Use https://www.soscisurvey.de/tools/view-chars.php to fix/change
		if ( tile.value > 0 && tile.value <= 9) {
			return stream << "  " << tile.value << " ";
		} else if ( tile.value >= 10) {
			return stream << " " << tile.value << " ";
		} else {
			return stream << "   ";
		}
	}	

	private:
		T value;
};
#endif
