#include "internal/point.hh"
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << (Point{ 1, 1 }.get_adjacent(Direction::UP)    == Point{ 1, 0 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent(Direction::DOWN)  == Point{ 1, 2 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent(Direction::LEFT)  == Point{ 0, 1 }) << '\n';
    std::cout << (Point{ 1, 1 }.get_adjacent(Direction::RIGHT) == Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 2, 1 }) << '\n';
    std::cout << (Point{ 1, 1 } != Point{ 1, 2 }) << '\n';
    std::cout << !(Point{ 1, 1 } != Point{ 1, 1 }) << '\n';

    return 0;
}


