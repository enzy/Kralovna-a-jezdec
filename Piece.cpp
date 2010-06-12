/* 
 * File:   Piece.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 12. červen 2010, 13:13
 */

#include "Piece.h"

Piece::Piece() {
    posX = posY = -1;
}

Piece::Piece(int x, int y) {
    posX = x;
    posY = y;
}

Piece::Piece(int x, int y, ChessBoard * _parentBoard) {
    Piece(x, y);
    parentBoard = _parentBoard;
}
