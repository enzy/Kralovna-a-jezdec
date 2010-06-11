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

ChessBoard::ChessBoard() {
    width = height = 8; // Standart size of Chessboard
    pawnCount = 8; // Standart count of pawns
    queenCount = 1;
    knightCount = 1;
    
    allocateMemory();    

    // TODO : Place pawns

    // TODO : Place queens

    // TODO : Place knights
}
ChessBoard::ChessBoard(int boardWidth, int boardHeight){
    width = boardWidth;
    height = boardHeight;
    pawnCount = 8;
    queenCount = 1;
    knightCount = 1;

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

ChessBoard::ChessBoard(const ChessBoard& orig) {
}

ChessBoard::~ChessBoard() {
    // Memory de-allocation to prevent memoty leak
    for (int i = 0; i < width; i++) {
        delete [] board[i];
    }
    delete [] board;
    // TODO : dealokace jednotlich poli
}

void ChessBoard::printToStd(){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[j][i].printToStd();
        }
        cout << endl;
    }
}

