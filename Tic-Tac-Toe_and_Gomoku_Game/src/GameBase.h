//
// Created by Chen Yifan on 11/11/23.
//

#ifndef CSE332LAB_GAMEBASE_H
#define CSE332LAB_GAMEBASE_H

#include<vector>
#include<string>

using namespace std;

class TicTacToeGame;

class GameBase {
protected:
    int width, height;
    unsigned int turnsPlayed;
    vector<vector<string>> board;
    size_t longestDisplayStringLength;
    unsigned int turns;
    string player1Symbol, player2Symbol, currentPlayer;

    void updateLongestStringLength(const string& piece);

public:
    GameBase(int width, int height, const string& player1Symbol, string player2Symbol);
    virtual void print() const = 0;
    virtual bool done() const = 0;
    virtual bool draw() const = 0;
    virtual int prompt(int& pieceRow, int& pieceCol);
    virtual int turn() = 0;
    int play();
    static GameBase* createGame(int argc, char* argv[]);
    virtual ~GameBase();
};


#endif //CSE332LAB_GAMEBASE_H
