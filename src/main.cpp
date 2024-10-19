#include "controller.cc"

auto main(int argc, char** argv) -> int {
	bool isRunning = false;
	Controller cntrl(Board{});
 
	// BUG: If I try to force "pull" the 13 value of the solved_board to empty tile. Weird thing is copied. Fix this
	std::cout << "Use [WASD] to move, [q] to quit\n";
	while(!isRunning) {
		std::cout << "Enter > ";
		cntrl.grab_input();
   }

   return 0;
}

