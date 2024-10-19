#include "direction.hh"
#include <utility>
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
	
	explicit Controller(Board board) : controller_board(board) {}

	void grab_input() {
		char kb = std::tolower(GETKB);
		switch(kb) {
			case '\n': break;
			case 'w':
				slide_up();
				break;
			case 'a':
				slide_left();
				break;
			case 's':
				slide_down();
				break;
			case 'd':
				slide_right();	
				break;
			case 'q':
				do_exit();
			default:
				break;
		}
		controller_board.display_board();
	}


private:

	bool slide_up() {
		return move_tile(Direction::UP);	
	}
	
	bool slide_down() {
		return move_tile(Direction::DOWN);
	}
	
	bool slide_left() {
		return move_tile(Direction::LEFT);
	}
	
	bool slide_right() {
		return move_tile(Direction::RIGHT);
	}

	void do_exit() {
		std::cout << "\n\nBYE\n\n";
		exit(0);
	}

	bool move_tile(Direction dir) {
		Point pt = controller_board.empty_at();	
		// We already check validity in get_adjacent. 
		// TODO: Implement a is_valid_tile_pos(Point& pt) in board class.
		Point adj_ops = pt.get_adjacent( -dir);
		if (adj_ops == pt) return false; // FIXME: Dubious check
		
		short pt_id = pt.index_at();
		short adj_ops_id = adj_ops.index_at();
		
		std::swap(controller_board.board[pt_id], controller_board.board[adj_ops_id]);
		return true;
	}

	Board controller_board;
};
