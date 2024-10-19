#ifndef POINT_HH
#define POINT_HH

#include "internal/direction.hh"
#include <string>

struct Point {
	constexpr Point(short x, short y) : x(x) , y(y) {
	}

	constexpr Point get_adjacent(Direction dir) {
		switch (dir) {
			using enum Direction;
			case LEFT:
				if (isValid(x - 1, y)) {
					return Point(x - 1, y);
				}
			case RIGHT:
				if (isValid(x + 1, y)) {
					return Point(x + 1, y);
				}
			case UP:
				if (isValid(x, y - 1)) {
					return Point(x, y - 1);
				}
			case DOWN:
				if (isValid(x, y + 1)) {
					return Point(x, y + 1);
				}
		}
		return Point(x, y); // FIXME: Send proper warning that adjacent is invalid.
	}
	
	std::string to_string() {
		return std::to_string(x) + " " +  std::to_string(y);
	}

	short index_at() {
		return y * 4 + x;
	}

	friend bool operator==(const Point& lhs, const Point& rhs);

private:
	[[nodiscard]] bool isValid(short x, short y) {
		return (((x >= 0 && x <= 4) && ((y >= 0) && (y <= 4))));
	}
	short x = 0 , y = 0;
};

inline bool operator==(const Point& lhs, const Point& rhs) {
	return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}
#endif
