# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name: Yifan Chen, Xin Zhao
Lab 4: 

Document your lab work here according to the lab specification

Warnings:
1. In file included from GameBase.cpp:5:
GameBase.h:20:12: warning: ‘GameBase::longestDisplayStringLength’ will be initialized after [-Wreorder]
     size_t longestDisplayStringLength;
            ^~~~~~~~~~~~~~~~~~~~~~~~~~
GameBase.h:18:18: warning:   ‘unsigned int GameBase::turnsPlayed’ [-Wreorder]
     unsigned int turnsPlayed;
                  ^~~~~~~~~~
2. GameBase.cpp:43:58: warning: comparison of integer expressions of different signedness: ‘unsigned int’ and ‘int’ [-Wsign-compare]
         if (!(iss >> pieceCol && pieceCol>=1 && pieceCol <= width)) {
                                                 ~~~~~~~~~^~~~~~~~
GameBase.cpp:46:66: warning: comparison of integer expressions of different signedness: ‘unsigned int’ and ‘int’ [-Wsign-compare]
         } else if (!(iss >> pieceRow && pieceRow >=1 && pieceRow <= height)) {
                                                         ~~~~~~~~~^~~~~~~~~
Errors:
1. GomokuGame.cpp: In member function ‘virtual int GomokuGame::turn()’:
GomokuGame.cpp:168:25: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
         result = prompt(x, y);
                         ^
In file included from GomokuGame.h:10,
                 from GomokuGame.cpp:7:
GameBase.h:31:17: note:   initializing argument 1 of ‘virtual int GameBase::prompt(int&, int&)’
     virtual int prompt(int& pieceRow, int& pieceCol);
                 ^~~~~~

Case1: 
[xin.zhao1@35 src]$ ./Main
Incorrect number of input parameter
usage: ./Main GameName

Case2:
[xin.zhao1@35 src]$ ./Main ssfjdks
Incorrect game name
usage: ./Main GameName(TicTacToe or Gomoku)

Case3:
[xin.zhao1@35 src]$ ./Main TicTacToe
3
2
1
X 1 2 3
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,2
Successfully extracted column index: 2
Successfully extracted row index: 2
3
2   X
1
X 1 2 3

Player X: 2,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,1
Successfully extracted column index: 1
Successfully extracted row index: 1
3
2   X
1 O
X 1 2 3

Player O: 1,1;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,1
Successfully extracted column index: 2
Successfully extracted row index: 1
3
2   X
1 O X
X 1 2 3

Player X: 2,1; 2,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,2
Successfully extracted column index: 1
Successfully extracted row index: 2
3
2 O X
1 O X
X 1 2 3

Player O: 1,1; 1,2;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,3
Successfully extracted column index: 2
Successfully extracted row index: 3
3   X
2 O X
1 O X
X 1 2 3

Player X: 2,1; 2,2; 2,3;
Player X wins

Case4:
[xin.zhao1@35 src]$ ./Main TicTacToe
3
2
1
X 1 2 3
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,2
Successfully extracted column index: 2
Successfully extracted row index: 2
3
2   X
1
X 1 2 3

Player X: 2,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,1
Successfully extracted column index: 1
Successfully extracted row index: 1
3
2   X
1 O
X 1 2 3

Player O: 1,1;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,1
Successfully extracted column index: 2
Successfully extracted row index: 1
3
2   X
1 O X
X 1 2 3

Player X: 2,1; 2,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,3
Successfully extracted column index: 2
Successfully extracted row index: 3
3   O
2   X
1 O X
X 1 2 3

Player O: 1,1; 2,3;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,2
Successfully extracted column index: 1
Successfully extracted row index: 2
3   O
2 X X
1 O X
X 1 2 3

Player X: 2,1; 1,2; 2,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,2
Successfully extracted column index: 3
Successfully extracted row index: 2
3   O
2 X X O
1 O X
X 1 2 3

Player O: 1,1; 3,2; 2,3;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,3
Successfully extracted column index: 1
Successfully extracted row index: 3
3 X O
2 X X O
1 O X
X 1 2 3

Player X: 2,1; 1,2; 2,2; 1,3;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,1
Successfully extracted column index: 3
Successfully extracted row index: 1
3 X O
2 X X O
1 O X O
X 1 2 3

Player O: 1,1; 3,1; 3,2; 2,3;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,3
Successfully extracted column index: 3
Successfully extracted row index: 3
3 X O X
2 X X O
1 O X O
X 1 2 3

Player X: 2,1; 1,2; 2,2; 1,3; 3,3;
Turns played: 9. No winning moves remain.

Case5:
[xin.zhao1@35 src]$ ./Main TicTacToe
3
2
1
X 1 2 3
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,1
Successfully extracted column index: 1
Successfully extracted row index: 1
3
2
1 X
X 1 2 3

Player X: 1,1;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,1
Invalid move to a non-empty location. Please provide another input as 'row_index,column_index'.
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,2
Successfully extracted column index: 2
Successfully extracted row index: 2
3
2   O
1 X
X 1 2 3

Player O: 2,2;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,2
Successfully extracted column index: 1
Successfully extracted row index: 2
3
2 X O
1 X
X 1 2 3

Player X: 1,1; 1,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,1
Successfully extracted column index: 2
Successfully extracted row index: 1
3
2 X O
1 X O
X 1 2 3

Player O: 2,1; 2,2;
Player X's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,1
Successfully extracted column index: 3
Successfully extracted row index: 1
3
2 X O
1 X O X
X 1 2 3

Player X: 1,1; 3,1; 1,2;
Player O's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,3
Successfully extracted column index: 2
Successfully extracted row index: 3
3   O
2 X O
1 X O X
X 1 2 3

Player O: 2,1; 2,2; 2,3;
Player O wins

Case6:
[xin.zhao1@35 src]$ ./Main Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,10
Successfully extracted column index: 3
Successfully extracted row index: 10
19
18
17
16
15
14
13
12
11
10       B
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 10;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
8,8
Successfully extracted column index: 8
Successfully extracted row index: 8
19
18
17
16
15
14
13
12
11
10       B
9
8                       W
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 8, 8;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,11
Successfully extracted column index: 3
Successfully extracted row index: 11
19
18
17
16
15
14
13
12
11       B
10       B
9
8                       W
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 10; 3, 11;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
4,6
Successfully extracted column index: 4
Successfully extracted row index: 6
19
18
17
16
15
14
13
12
11       B
10       B
9
8                       W
7
6           W
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 4, 6; 8, 8;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,12
Successfully extracted column index: 3
Successfully extracted row index: 12
19
18
17
16
15
14
13
12       B
11       B
10       B
9
8                       W
7
6           W
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 10; 3, 11; 3, 12;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
4,5
Successfully extracted column index: 4
Successfully extracted row index: 5
19
18
17
16
15
14
13
12       B
11       B
10       B
9
8                       W
7
6           W
5           W
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 4, 5; 4, 6; 8, 8;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,13
Successfully extracted column index: 3
Successfully extracted row index: 13
19
18
17
16
15
14
13       B
12       B
11       B
10       B
9
8                       W
7
6           W
5           W
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 10; 3, 11; 3, 12; 3, 13;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
6,5
Successfully extracted column index: 6
Successfully extracted row index: 5
19
18
17
16
15
14
13       B
12       B
11       B
10       B
9
8                       W
7
6           W
5           W     W
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 4, 5; 6, 5; 4, 6; 8, 8;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,14
Successfully extracted column index: 3
Successfully extracted row index: 14
19
18
17
16
15
14       B
13       B
12       B
11       B
10       B
9
8                       W
7
6           W
5           W     W
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 10; 3, 11; 3, 12; 3, 13; 3, 14;
Player B wins

Case7:
[xin.zhao1@35 src]$ ./Main Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
10,10
Successfully extracted column index: 10
Successfully extracted row index: 10
19
18
17
16
15
14
13
12
11
10                            B
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 10, 10;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
6,6
Successfully extracted column index: 6
Successfully extracted row index: 6
19
18
17
16
15
14
13
12
11
10                            B
9
8
7
6                 W
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 6, 6;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
11,2
Successfully extracted column index: 11
Successfully extracted row index: 2
19
18
17
16
15
14
13
12
11
10                            B
9
8
7
6                 W
5
4
3
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 11, 2; 10, 10;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
5,5
Successfully extracted column index: 5
Successfully extracted row index: 5
19
18
17
16
15
14
13
12
11
10                            B
9
8
7
6                 W
5              W
4
3
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 5, 5; 6, 6;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
4,12
Successfully extracted column index: 4
Successfully extracted row index: 12
19
18
17
16
15
14
13
12          B
11
10                            B
9
8
7
6                 W
5              W
4
3
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 11, 2; 10, 10; 4, 12;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,3
Successfully extracted column index: 3
Successfully extracted row index: 3
19
18
17
16
15
14
13
12          B
11
10                            B
9
8
7
6                 W
5              W
4
3        W
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 3, 3; 5, 5; 6, 6;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
8,9
Successfully extracted column index: 8
Successfully extracted row index: 9
19
18
17
16
15
14
13
12          B
11
10                            B
9                       B
8
7
6                 W
5              W
4
3        W
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 11, 2; 8, 9; 10, 10; 4, 12;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
4,4
Successfully extracted column index: 4
Successfully extracted row index: 4
19
18
17
16
15
14
13
12          B
11
10                            B
9                       B
8
7
6                 W
5              W
4           W
3        W
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 3, 3; 4, 4; 5, 5; 6, 6;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
1,10
Successfully extracted column index: 1
Successfully extracted row index: 10
19
18
17
16
15
14
13
12          B
11
10 B                          B
9                       B
8
7
6                 W
5              W
4           W
3        W
2                                B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 11, 2; 8, 9; 1, 10; 10, 10; 4, 12;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
2,2
Successfully extracted column index: 2
Successfully extracted row index: 2
19
18
17
16
15
14
13
12          B
11
10 B                          B
9                       B
8
7
6                 W
5              W
4           W
3        W
2     W                          B
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 2, 2; 3, 3; 4, 4; 5, 5; 6, 6;
Player W wins

Case8:
[xin.zhao1@35 src]$ ./Main Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,3
Successfully extracted column index: 3
Successfully extracted row index: 3
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3        B
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player B: 3, 3;
Player W's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
3,3
Invalid move to a non-empty location. Please provide another input as 'row_index,column_index'.
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
4,4
Successfully extracted column index: 4
Successfully extracted row index: 4
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4           W
3        B
2
1
X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Player W: 4, 4;
Player B's turn
Type 'quit' to quit game or 'column index, row index' to give a location of your next move...
quit
Turns played:2. Player B quits
