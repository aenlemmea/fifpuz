#if defined (_WIN64)
	#include <conio.h>
	#define GETKB getch()
#elif defined(__linux__)
	#include <cstdio>
	#define GETKB getchar()
#endif

#include "board.cc"

class Controller {
public:
	Controller() = default;
	
	explicit Controller(Board board) : board(board) {}

	void grab_input() {
		char kb = std::tolower(GETKB);
		switch(kb) {
			case '\n': break;
			case 'w':
				board.slide_up();
				break;
			case 'a':
				board.slide_left();
				break;
			case 's':
				board.slide_down();
				break;
			case 'd':
				board.slide_right();	
				break;
			case 'q':
				board.do_exit();
			default:
				break;
		}
		board.display_board();
	}

private:
	Board board;
};
