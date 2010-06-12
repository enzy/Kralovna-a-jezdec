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

bool ChessBoard::isOutOfBoard(int x, int y) {
    return x < 0 || y < 0 || x >= width || y >= height;
}

bool ChessBoard::movePiece(int fromX, int fromY, int toX, int toY) {
    if (isOutOfBoard(fromX, fromY) || isOutOfBoard(toX, toY)) return false;
    if (!board[toX][toY].isEmpty() || board[fromX][fromY].isEmpty()) return false;

    if (board[fromX][fromY].isPawn()) {
        board[toX][toY].setPawn();
        board[fromX][fromY].erase();
        return true;
    }

    if (board[fromX][fromY].isKnight()) {
        board[toX][toY].setKnight();
        board[fromX][fromY].erase();
        return true;
    }

    if (board[fromX][fromY].isQueen()) {
        board[toX][toY].setQueen();
        board[fromX][fromY].erase();
        return true;
    }

    return false;
}

bool ChessBoard::insertPawn(int x, int y) {
    if (isOutOfBoard(x, y)) return false;
    if (!board[x][y].isEmpty()) return false;

    board[x][y].setPawn();

    pawnCount++;
    freeSquares--;

    return true;
}

void ChessBoard::insertRandomPawns(int pawnCountToInsert) {
    if (pawnCountToInsert > freeSquares) return;
    int pawnCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place pawns on random spots
    while (pawnCountInserted < pawnCountToInsert) {

        int randomX = rand() % width;
        int randomY = rand() % height;

        if (insertPawn(randomX, randomY)) {
            pawnCountInserted++;
        } else {
            continue;
        }

    }
}

bool ChessBoard::insertKnight(int x, int y) {
    if (isOutOfBoard(x, y)) return false;
    if (!board[x][y].isEmpty()) return false;

    board[x][y].setKnight();

    knightCount++;
    freeSquares--;

    return true;
}

void ChessBoard::insertRandomKnights(int knightCountToInsert) {
    if (knightCountToInsert > freeSquares) return;
    int knightCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place knights on random spots
    while (knightCountInserted < knightCountToInsert) {
        int randomX = rand() % width;
        int randomY = rand() % height;

        if (insertKnight(randomX, randomY)) {
            knightCountInserted++;
        } else {
            continue;
        }
    }
}

bool ChessBoard::insertQueen(int x, int y) {
    if (isOutOfBoard(x, y)) return false;
    if (!board[x][y].isEmpty()) return false;

    board[x][y].setQueen();

    queenCount++;
    freeSquares--;

    return true;
}

void ChessBoard::insertRandomQueens(int queenCountToInsert) {
    if (queenCountToInsert > freeSquares) return;
    int queenCountInserted = 0;

    srand(time(NULL)); // Initialize random seed

    // Place knights on random spots
    while (queenCountInserted < queenCountToInsert) {
        int randomX = rand() % width;
        int randomY = rand() % height;

        if (insertQueen(randomX, randomY)) {
            queenCountInserted++;
        } else {
            continue;
        }
    }
}

