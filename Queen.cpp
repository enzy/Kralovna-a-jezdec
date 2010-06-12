/* 
 * File:   Queen.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 9. červen 2010, 18:18
 */

#include "Queen.h"

Queen::Queen() {
    Piece();
}

Queen::Queen(int x, int y) {
    Piece(x, y);
}

Queen::Queen(int x, int y, ChessBoard* _parentBoard) {
    Piece(x, y, _parentBoard);
}

Position Queen::findNextMove() {

}
