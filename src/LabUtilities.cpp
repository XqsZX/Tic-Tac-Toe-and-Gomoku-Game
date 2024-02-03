//
// Created by Chen Yifan on 11/13/23.
//
#include "LabUtilities.h"
#include <string>
#include <iostream>

using namespace std;

int usage(int argc, char* argv[]) {
    if (argc != CmdLineIndices::expectedInputCount){
        cout << "Incorrect number of input parameter" << endl;
        cout << "usage: " << argv[CmdLineIndices::programName] << " GameName" << endl;
        return ProgramStatusCode::incorrectInputNumber;
    } else if (string(argv[CmdLineIndices::programName]) != "TicTacToe" || string(argv[CmdLineIndices::programName]) != "Gomoku") {
        cout << "Incorrect game name" << endl;
        cout << "usage: " << argv[CmdLineIndices::programName] << " GameName(TicTacToe or Gomoku)" << endl;
        return ProgramStatusCode::incorrectGameName;
    }
    return 0;
}
