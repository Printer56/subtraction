#include <iostream>
#include <vector>
#include "subtraction.hpp"

int main() {
    std::vector<int> left { 1, 2 };
    std::vector<int> right { 2, 3 };
    int stack;

    std::cout << "Enter a nonnegative value for the main game stack: ";
    std::cin >> stack;

    Subtraction game = Subtraction(left, right, stack);

    int result = game.playGame();
    result ? std::cout << "Right wins!" << std::endl : std::cout << "Left wins!" << std::endl;

    return 0;
}