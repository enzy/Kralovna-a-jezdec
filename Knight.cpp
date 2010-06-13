/* 
 * File:   Knight.cpp
 * Author: Matěj Šimek - www.matejsimek.cz
 * 
 * Created on 9. červen 2010, 18:19
 */

#include "Knight.h"

Knight::Knight() {
    posX = posY = -1;
}

Knight::Knight(int x, int y) {
    posX = x;
    posY = y;
}

Knight::Knight(int x, int y, ChessBoard * _parentBoard) {
    posX = x;
    posY = y;
    parentBoard = _parentBoard;
}

Position Knight::findNextMove() {

}


