//
// Created by Chen Yifan on 11/11/23.
//

#include "GameBase.h"
#include <iostream>
#include "LabUtilities.h"
#include <sstream>
#include <utility>
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include <algorithm>

void GameBase::updateLongestStringLength(const std::string &piece) {
    if (piece.length() > longestDisplayStringLength) {
        longestDisplayStringLength = piece.length();
    }
}

GameBase::GameBase(int width, int height, const string& player1Symbol, string player2Symbol):
    width(width), height(height), turnsPlayed(0), 
    board(height, vector<string>(width, " ")),
    longestDisplayStringLength(2), turns(0),
    player1Symbol(player1Symbol), player2Symbol(std::move(player2Symbol)), currentPlayer(player1Symbol) {}

int GameBase::prompt(int &pieceCol, int &pieceRow) {
    string userInstruction;
    while (true) {
        cout << "Type 'quit' to quit game or 'column index, row index' to give a location of your next move..." << endl;

        getline(cin, userInstruction);

        if (userInstruction == "quit") {
            return ProgramStatusCode::quit;
        }

        replace(userInstruction.begin(), userInstruction.end(), ',', ' ');

        istringstream iss(userInstruction);

        if (!(iss >> pieceCol && pieceCol>=1 && pieceCol <= width)) {
            cout << "Failed to extract the column index." << endl;
            continue;
        } else if (!(iss >> pieceRow && pieceRow >=1 && pieceRow <= height)) {
            cout << "Failed to extract the row index." << endl;
            continue;
        }

        // Check for any extra data after the row and column values
        string extra_data;
        if (iss >> extra_data) {
            cout << "Invalid format. Please provide input as 'row_index,column_index'." << endl;
            continue;
        }

        // check if the locaiton of the move is an empty square
        string checked = board[pieceRow-1][pieceCol-1];
        if (checked != " ") {
            cout << "Invalid move to a non-empty location. Please provide another input as 'row_index,column_index'." << endl;
            continue;
        }

        cout << "Successfully extracted column index: " << pieceCol << endl;
        cout << "Successfully extracted row index: " << pieceRow << endl;
        break;
    }
    return ProgramStatusCode::success;
}

int GameBase::play() {
    print();
    while (true) {
        if (turn() == ProgramStatusCode::quit) {
            cout << "Turns played:" << turns << ". Player " << currentPlayer << " quits" << endl;
            return ProgramStatusCode::quit;
        }
        if (done()) {
            if (currentPlayer == player2Symbol) {
                cout << "Player " << player1Symbol << " wins" << endl;
                return ProgramStatusCode::success;
            } else {
                cout << "Player " << player2Symbol << " wins" << endl;
                return ProgramStatusCode::success;
            }
        }
        if (draw()) {
            cout << "Turns played: " << turns << ". No winning moves remain." << endl;
            return ProgramStatusCode::draw;
        }
    }
}

GameBase *GameBase::createGame(int argc, char* argv[]) {
    if (argc == CmdLineIndices::expectedInputCount) {
        if (string(argv[CmdLineIndices::gameName]) == "TicTacToe") {
            return new TicTacToeGame();
        } else if (string(argv[CmdLineIndices::gameName]) == "Gomoku") {
            return new GomokuGame();
        }
    }
    return nullptr;
}

GameBase::~GameBase() = default;
