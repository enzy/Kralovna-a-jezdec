/* 
 * File:   ChessBoard.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 12. květen 2010, 22:47
 */

#include <stddef.h>

#include "ChessBoard.h"

#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"

#include <iostream>
using namespace std;

#include <ctime>

ChessBoard::ChessBoard() {
    width = height = 8; // Standart size of Chessboard
    pawnCount = queenCount = knightCount = 0;
    freeSquares = width * height;

    allocateMemory();
}

ChessBoard::ChessBoard(int boardWidth, int boardHeight) {
    width = boardWidth;
    height = boardHeight;
    pawnCount = queenCount = knightCount = 0;
    freeSquares = width * height;

    allocateMemory();
}

bool ChessBoard::allocateMemory() {
    // TODO : Inicializace jednotlivych poli
    board = new Square * [width];
    for (int i = 0; i < width; i++) {
        board[i] = new Square[height];
    }
    if (board != NULL) return true;
    else return false;
}

ChessBoard::~ChessBoard() {
    // Memory de-allocation to prevent memoty leak
    for (int i = 0; i < width; i++) {
        delete [] board[i];
    }
    delete [] board;
    // TODO : dealokace jednotlich poli
}

void ChessBoard::printToStd() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "+---";
        }

        cout << "+" << endl;

        for (int j = 0; j < width; j++) {
            board[j][i].printToStd();
        }
        cout << "|" << endl;
    }

    for (int i = 0; i < width; i++) {
        cout << "+---";
    }
    cout << "+" << endl;

}

void ChessBoard::insertRandomPawns(int pawnCountToInsert) {
    if (pawnCountToInsert > freeSquares) return;
    int pawnCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place pawns on random spots
    while (pawnCountInserted < pawnCountToInsert) {

        int randomX = rand() % width;
        int randomY = rand() % height;

        if (board[randomX][randomY].isEmpty()) {
            board[randomX][randomY].setPawn();
            pawnCountInserted++;
        } else {
            continue;
        }

    }

    pawnCount += pawnCountInserted;
    freeSquares -= pawnCountInserted;

}

void ChessBoard::insertRandomKnights(int knightCountToInsert) {
    if (knightCountToInsert > freeSquares) return;
    int knightCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place knights on random spots
    while (knightCountInserted < knightCountToInsert) {
        int randomX = rand() % width;
        int randomY = rand() % height;

        if (board[randomX][randomY].isEmpty()) {
            board[randomX][randomY].setKnight();
            knightCountInserted++;
        } else {
            continue;
        }
    }

    knightCount += knightCountInserted;
    freeSquares -= knightCountInserted;
}

void ChessBoard::insertRandomQueens(int queenCountToInsert) {
    if(queenCountToInsert > freeSquares) return;
    int queenCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place knights on random spots
    while (queenCountInserted < queenCountToInsert) {
        int randomX = rand() % width;
        int randomY = rand() % height;

        if (board[randomX][randomY].isEmpty()) {
            board[randomX][randomY].setQueen();
            queenCountInserted++;
        } else {
            continue;
        }
    }

    queenCount += queenCountInserted;
    freeSquares -= queenCountInserted;
}

