/**
 * Main.cpp
 * CSE 332S
 * Lab Num:
 * Author:
*/

#include <iostream>
#include <memory>
#include "GameBase.h"
#include "TicTacToeGame.h"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        shared_ptr<GameBase> game(GameBase::createGame(argc, argv));
        if (!game) {
            return usage(argc, argv);
        }
        return game->play();
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
        return ProgramStatusCode::badAllocation;
    } catch (const exception& e) {
        std::cerr << "Exception: " << e.what() << endl;
        return ProgramStatusCode::unknownError;
    }
}
