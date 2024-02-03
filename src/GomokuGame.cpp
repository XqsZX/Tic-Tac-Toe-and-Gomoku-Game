/* ************************************************************************
> File Name:     GomokuGame.cpp
> Author:        XIN ZHAO
> Created Time:  Wed Nov 15 09:33:12 2023
> Description:   Definition for Gomoku class
 ************************************************************************/
#include "GomokuGame.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor for GomokuGame
GomokuGame::GomokuGame(int size) : GameBase(size, size, "B", "W") {}

ostream& operator<<(ostream& os, const GomokuGame& GMKgame) {
    // Print the row labels
    for (int row = GMKgame.height; row > 0; --row) {
        if (row < GomokuUtilities::divide) os << row << " ";
        else os << row;
        for (int col = 1; col < GMKgame.width + 1; ++col) 
            os << " " << GMKgame.board[row - 1][col - 1] << " ";

        os << endl;
    }

    // Print the col labels
    os << "X ";
    for (int col = 1; col <= GMKgame.width; ++col) {
        if (col < GomokuUtilities::divide) cout << " " << col << " ";
        else cout << col << " ";
    }

    os << endl;

    return os;
}

// Override the print method
void GomokuGame::print() const {
    cout << *this;
}

bool GomokuGame::checkRows() const {
    for (int row = 0; row < height; ++row) {
        int Count = 0;
        string lastStone = " ";

        for (int col = 0; col < width; ++col) {
            const string& currentStone = board[row][col];

            if (currentStone != " " && currentStone == lastStone) {
                ++Count;

                if (Count == GomokuUtilities::win_num - 1) return true;
            } else {
                Count = 0;
            }

            lastStone = currentStone;
        }
    }

    return false;
}

bool GomokuGame::checkCols() const {
    for (int col = 0; col < width; ++col) {
        int Count = 0;
        string lastStone = " ";

        for (int row = 0; row < height; ++row) {
            const string& currentStone = board[row][col];

            if (currentStone != " " && currentStone == lastStone) {
                ++Count;

                if (Count == GomokuUtilities::win_num - 1) return true;
            } else {
                Count = 0;
            }

            lastStone = currentStone;
        }
    }

    return false;
}

bool GomokuGame::checkDiagonals() const {
    for (int row = 0; row <= height - GomokuUtilities::win_num; ++row) {
        for (int col = 0; col <= width - GomokuUtilities::win_num; ++col) {
            if (checkDiagonal(row, col, 1, 1)) return true;
        }
    }

    for (int row = GomokuUtilities::win_num - 1; row < height; ++row) {
        for (int col = 0; col <= width - GomokuUtilities::win_num; ++col) {
            if (checkDiagonal(row, col, -1, 1)) return true;
        }
    }

    return false;
}

bool GomokuGame::checkDiagonal(int startRow, int startCol, int rowCo, int colCo) const {
    string lastStone = board[startRow][startCol];
    int Count = (lastStone == " " ? 0 : 1);

    for (int i = 1; i < GomokuUtilities::win_num; ++i) {
        int currentRow = startRow + rowCo * i;
        int currentCol = startCol + colCo * i;
        const string& currentStone = board[currentRow][currentCol];

        if (currentStone != " " && currentStone == lastStone) {
            ++Count;
            if (Count == GomokuUtilities::win_num) return true;
        } else {
            break;
        }
    }

    return false;
}

bool GomokuGame::checkDirection(int row, int col, int rowCo, int colCo, const string& Player) const {
    int Count = 0;

    for (int i = 0; i < GomokuUtilities::win_num; ++i) {
        int currentRow = row + rowCo * i;
        int currentCol = col + colCo * i;

        // Boundaries
        if (currentRow < 0 || currentRow >= height || currentCol < 0 || currentCol >= width) return false;

        // Check the position
        if (board[currentRow][currentCol] != Player && board[currentRow][currentCol] != " ") return false;

        if (board[currentRow][currentCol] == Player) ++Count;
    }

    return Count < GomokuUtilities::win_num;
}

bool GomokuGame::isPotential(int row, int col, const string& Player) const {
    return checkDirection(row, col, 1, 0, Player) ||
           checkDirection(row, col, 0, 1, Player) ||
           checkDirection(row, col, 1, 1, Player) ||
           checkDirection(row, col, 1, -1, Player);
}

bool GomokuGame::done() const {
    return checkRows() || checkCols() || checkDiagonals();
}

bool GomokuGame::draw() const {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (board[row][col] == " " && (isPotential(row, col, "B") || isPotential(row, col, "W"))) return false;
        }
    }

    return true;
}

int GomokuGame::turn() {
    cout << "Player " << currentPlayer << "'s turn" << endl;

    int pieceCol, pieceRow;

    if (prompt(pieceCol, pieceRow) == ProgramStatusCode::quit) {
        return ProgramStatusCode::quit;
    }
    
    // increment turns played
    ++turns;

    board[pieceRow-1][pieceCol-1] = currentPlayer;

    // Print after Player moves
    print();
    cout << "" << endl;

    // Print out valid moves that made by current Player
    cout << "Player " << currentPlayer << ": ";
    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            if (currentPlayer == board[r][c]) cout << c + 1 << ", " << r + 1 << "; ";
        }
    }
    cout << endl;

    currentPlayer = (currentPlayer == "B" ? "W" : "B");

    return ProgramStatusCode::success;
}
