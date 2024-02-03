/* ************************************************************************
> File Name:     GomokuGame.h
> Author:        XIN ZHAO
> Created Time:  Tue Nov 14 20:51:37 2023
> Description:   
 ************************************************************************/
#ifndef GOMOKUGAME_H
#define GOMOKUGAME_H

#include "GameBase.h"
#include "LabUtilities.h"
#include <vector>
#include <string>

using namespace std;

class GomokuGame : public GameBase {
public:
    // Set the default size to GomokuUtilities::board_size
    GomokuGame(int size = GomokuUtilities::board_size);

    bool checkRows() const;
    bool checkCols() const;
    bool checkDiagonals() const;

    bool checkDiagonal(int startRow, int startCol, int rowCo, int colCo) const;
    bool checkDirection(int row, int col, int rowCo, int colCo, const string& Player) const;

    bool isPotential(int row, int col, const string& Player) const;

    // Override virtual functions from GameBase
    virtual void print() const override;
    virtual bool done() const override;
    virtual bool draw() const override;
    virtual int turn() override;

    // Friend declaration for insertion operator
    friend ostream& operator<<(ostream& os, const GomokuGame& GMKgame);
};

#endif //CSE332GOMOKUGAME_H
