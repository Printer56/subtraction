#ifndef SUBTRACTION_HPP
#define SUBTRACTION_HPP

#include <iostream>
#include <vector>
#include <algorithm> // std::any_of()
#include <limits> // getting weird error with numeric_limits<streamsize>::max() and apparently this will fix it

enum Turn {
    RIGHT = 0,
    LEFT = 1
};

class Subtraction {
public:
    // Function declarations
    Subtraction(std::vector<int> leftMoves, std::vector<int> rightMoves, int stackNum, Turn leftMove=LEFT);
    std::vector<int> getPossibleMoves(std::vector<int> moves);
    void printMoves(std::vector<int> moves);
    void makeMove(std::vector<int> moves, int move=0);
    int playGame();
    int botPlayGame();

private:
    // Left's and right's moves
    std::vector<int> left;
    std::vector<int> right;

    // Main stack for the game
    int stack;

    // Determines whos turn it is
    Turn turn;
};

#endif