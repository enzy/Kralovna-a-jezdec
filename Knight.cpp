/* 
 * File:   Knight.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 9. červen 2010, 18:19
 */

#include "Knight.h"

Knight::Knight() {
    Piece();
}

Knight::Knight(int x, int y) {
    Piece(x, y);
}

Knight::Knight(int x, int y, ChessBoard* _parentBoard) {
    Piece(x, y, _parentBoard);
}

Position Knight::findNextMove() {

}


