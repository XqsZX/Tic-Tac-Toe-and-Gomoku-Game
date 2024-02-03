//
// Created by Chen Yifan on 11/13/23.
//

#ifndef CSE332LAB_LABUTILITIES_H
#define CSE332LAB_LABUTILITIES_H

enum CmdLineIndices {
    programName=0,
    gameName = 1,
    expectedInputCount=2
};

enum ProgramStatusCode {
    success=0,
    incorrectInputNumber=1,
    quit=2,
    draw=3,
    incorrectGameName=4,
    badAllocation=5,
    unknownError=6
};

enum GomokuUtilities {
    board_size = 19,
    win_num = 5,
    divide = 10
};

int usage(int argc, char* argv[]);

#endif //CSE332LAB_LABUTILITIES_H
