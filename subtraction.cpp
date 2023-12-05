#include "subtraction.hpp"

Subtraction::Subtraction(std::vector<int> leftMoves, std::vector<int> rightMoves, int stackNum, Turn move) {
    // Constructor
    left = leftMoves;
    right = rightMoves;
    stack = stackNum;
    turn = move;
}

std::vector<int> Subtraction::getPossibleMoves(std::vector<int> moves) {
    // Returns all POSSIBLE moves
    std::vector<int> possibleMoves;

    for(auto move : moves) {
        if(stack - move >= 0) {
            possibleMoves.push_back(move);
        }
    }
    return possibleMoves;
}

void Subtraction::printMoves(std::vector<int> moves) {
    // Prints the given moves and makes them look nice
    for(auto move : moves) {
        if(move == moves[moves.size() - 1]) {
            std::cout << move << std::endl;
            break;
        }
        std::cout << move << ", ";
    }
}

void Subtraction::makeMove(std::vector<int> moves, int move) {
    if(!move) {
        for(;;) {
            std::cout << "Possible moves: "; printMoves(moves);
            turn == LEFT ? std::cout << "Left: " : std::cout << "Right: ";
            if(std::cin >> move) {
                if (any_of(moves.begin(), moves.end(), [&](int m){return m == move;})) {
                    break; // Valid move, break out of the loop
                }
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << "Invalid move." << std::endl;
        }
    }

    stack -= move;
}

int Subtraction::playGame() {
    // Game runs until stack runs out, or the current player does not have any possible moves
    while(stack > 0) {
        // Gets (and tests) for moves
        std::vector<int> moves;
        moves = (turn == LEFT) ? getPossibleMoves(left) : getPossibleMoves(right);
        if(moves.size() == 0) break;

        // If there are moves, continue game like normal
        std::cout << stack << std::endl;
        makeMove(moves);
        // Set it to next player's turn
        turn = (turn == LEFT) ? RIGHT : LEFT;
    }

    return turn;
}

int Subtraction::botPlayGame() {
    // Game runs until stack runs out, or the current player does not have any possible moves
    while(stack > 0) {
        // Gets (and tests) for moves
        std::vector<int> moves;
        moves = (turn == LEFT) ? getPossibleMoves(left) : getPossibleMoves(right);
        if(moves.size() == 0) break;

        // If there are moves, continue game like normal
        std::cout << stack << std::endl;
        makeMove(moves);
        // Set it to next player's turn
        turn = (turn == LEFT) ? RIGHT : LEFT;
    }

    return turn;
}