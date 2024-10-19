#include "controller.cc"

auto main(int argc, char** argv) -> int {
	bool isRunning = false;
	Controller cntrl(Board{});
 

	std::cout << "Use [WASD] to move, [q] to quit\n";
	while(!isRunning) {
		std::cout << "Enter > ";
		cntrl.grab_input();
   }

   return 0;
}

