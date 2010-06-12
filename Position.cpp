/* 
 * File:   Position.cpp
 * Author: Enzy
 * 
 * Created on 12. červen 2010, 17:19
 */

#include "Position.h"

Position::Position() {
    x = y = 0;
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::Position(const Position& orig) {
    x = orig->x;
    y = orig->y;
}

