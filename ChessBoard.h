/* 
 * File:   ChessBoard.h
 * Author: Enzy
 *
 * Created on 12. květen 2010, 22:47
 */

#ifndef _CHESSBOARD_H
#define	_CHESSBOARD_H

#include "Square.h"


class ChessBoard {
public:
    ChessBoard();
    ChessBoard(const ChessBoard& orig);
    virtual ~ChessBoard();

    /**
     * Chessboard width (in squares)
     */
    int width;
    /**
     * Chessboard height (in squares)
     */
    int height;

    /**
     * Chessboard (from squares)
     */
    Square ** board;

    /**
     * Number of pawns on chessboard
     */
    int pawnCount;
    
    /**
     * Number of queens on chessboard
     */
    int queenCount;

    /**
     * Nubmer of knights on chessboard
     */
    int knightCount;


private:

};

#endif	/* _CHESSBOARD_H */

