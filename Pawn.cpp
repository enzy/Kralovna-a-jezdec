/* 
 * File:   Pawn.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 9. červen 2010, 18:23
 */

#include "Pawn.h"

Pawn::Pawn() {
    Piece();
}

Pawn::Pawn(int x, int y) {
    Piece(x, y);
}

Pawn::Pawn(int x, int y, ChessBoard* _parentBoard) {
    Piece(x, y, _parentBoard);
}
