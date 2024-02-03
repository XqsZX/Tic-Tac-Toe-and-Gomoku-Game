//
// Created by Chen Yifan on 11/11/23.
//

#ifndef CSE332LAB_TICTACTOEGAME_H
#define CSE332LAB_TICTACTOEGAME_H
#include "GameBase.h"
#include "LabUtilities.h"

class TicTacToeGame : public GameBase {
private:
    friend ostream& operator<<(ostream& stream, const TicTacToeGame& gameBase);
public:
    TicTacToeGame();
    void print() const override;
    bool done() const override;
    bool draw() const override;
    int turn() override;
};


#endif //CSE332LAB_TICTACTOEGAME_H
