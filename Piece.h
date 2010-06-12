/* 
 * File:   Piece.h
 * Author: Matěj Šimek - www.matejsimek.cz
 *
 * Created on 12. červen 2010, 13:13
 */

#ifndef PIECE_H
#define	PIECE_H

#include "Position.h"
#include "ChessBoard.h"

class Piece {
public:
    /**
     * Create empty piece with no position (-1,-1)
     */
    Piece();
    /**
     * Create empty piece on entered position [x,y]
     * @param x
     * @param y
     */
    Piece(int x, int y);

    /**
     * Create empty piece on entered position [x, y] on entered chessboard
     * @param x
     * @param y
     * @param parentBoard chessboard where to place piece
     */
    Piece(int x, int y, ChessBoard * _parentBoard);    

    /**
     * Current X position
     */
    int posX;

    /**
     * Current Y position
     */
    int posY;

    /**
     * Pointer to chessboard where piece is placed
     */
    ChessBoard * parentBoard;

    /**
     * Finds next move to the closest pawn
     * @return Position to move
     */
    Position findNextMove();
    
private:

};

#endif	/* PIECE_H */

