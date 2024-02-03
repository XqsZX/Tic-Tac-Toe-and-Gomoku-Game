//
// Created by Chen Yifan on 11/11/23.
//
#include <iostream>
#include "TicTacToeGame.h"
#include <iomanip>

TicTacToeGame::TicTacToeGame() :
    GameBase(3, 3, "X", "O") {}

void TicTacToeGame::print() const {
    cout << *this << endl;
}

bool TicTacToeGame::done() const {
    bool is_done = false;

    // check horizontal pieces
    for (int r = 0; r < height; r++) {
        string first_in_row = board[r][0];
        if (first_in_row == " ") {
            continue;
        }
        string second_in_row = board[r][1];
        string third_in_row = board[r][2];

        if (first_in_row == second_in_row && second_in_row == third_in_row) {
            is_done = true;
            break;
        }
    }
    if (is_done) {
        return is_done;
    }

    // check vertical pieces
    for (int c = 0; c < width; c++) {
        string first_in_col = board[0][c];
        if (first_in_col == " ") {
            continue;
        }
        string second_in_col = board[1][c];
        string third_in_col = board[2][c];
        if (first_in_col == second_in_col && second_in_col == third_in_col) {
            is_done = true;
            break;
        }
    }
    if (is_done) {
        return is_done;
    }

    // check anti-diagonal pieces
    string first_in_line = board[0][0];
    if (first_in_line != " ") {
        string second_in_line = board[1][1];
        string third_in_line = board[2][2];
        if (first_in_line == second_in_line && second_in_line== third_in_line) {
            is_done = true;
        }
    }
    if (is_done) {
        return is_done;
    }

    // check diagonal pieces
    first_in_line = board[2][0];
    if (first_in_line != " ") {
        string second_in_line = board[1][1];
        string third_in_line = board[0][2];
        if (first_in_line == second_in_line && second_in_line == third_in_line) {
            is_done = true;
        }
    }
    if (is_done) {
        return is_done;
    }
    return is_done;
}

bool TicTacToeGame::draw() const {
    if (done()) {
        return false;
    }
    for (const vector<string>& row : board) {
        for (const string& piece : row) {
            if (piece == " "){
                return false;
            }
        }
    }
    return true;
}

int TicTacToeGame::turn() {
    cout << "Player " << currentPlayer <<"'s turn" << endl;
    int pieceCol, pieceRow;
    if(prompt(pieceCol, pieceRow)==ProgramStatusCode::quit) {
        return ProgramStatusCode::quit;
    }

    // increment turns played
    turns++;

    // if a valid move has been made, move the piece to the square
    board[pieceRow-1][pieceCol-1] = currentPlayer;

    // update display string's largest length
    updateLongestStringLength(currentPlayer);

    // print  out the updated game board
    print();
    cout << "" << endl;

    // print out valid moves that have been made by current player
    cout << "Player " << currentPlayer << ": ";
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (currentPlayer == board[r][c]) {
                cout << c+1 << "," << r+1 << "; ";
            }
        }
    }
    cout << endl;

    // alternate player's turn
    if (currentPlayer == player1Symbol) {
        currentPlayer = player2Symbol;
    } else {
        currentPlayer = player1Symbol;
    }
    return ProgramStatusCode::success;
};

ostream &operator<<(ostream &stream, const TicTacToeGame &game) {
    // Determine the width needed for the row numbers
    int rowNumberWidth = to_string(game.height - 1).length();

    // Determine the width needed for the column numbers and displayed string
    int colWidth = game.longestDisplayStringLength;

    // print out piece
    for (int i = game.height - 1; i != -1; i--) {
        stream << setw(rowNumberWidth) << i+1;
        for (int j = 0; j < game.width; j++) {
            stream << setw(colWidth)
                   << game.board[i][j];
        }
        stream << std::endl;
    }

    // print out col number at bottom
    cout << setw(rowNumberWidth) << "X";
    for (int i = 0; i  < game.width; i++) {
        cout << setw(colWidth) << i+1;
    }

    return stream;
}
