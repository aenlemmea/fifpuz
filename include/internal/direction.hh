#ifndef DIRECTION_HH
#define DIRECTION_HH
	
#include <ostream>
enum class Direction : char {
	LEFT = 'a',
	RIGHT = 'd',
	DOWN = 's',
	UP = 'w'
};

inline std::ostream& operator<<(std::ostream& stream, Direction dir) {
	switch(dir) {
		using enum Direction;
		case LEFT:
			return stream << "Going left" << "\n";
		case RIGHT:
			return stream << "Going right" << "\n";
		case DOWN:
			return stream << "Going left" << "\n";
		case UP:
			return stream << "Going up" << "\n";
	}
}	

#endif
