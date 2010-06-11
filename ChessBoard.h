/* 
 * File:   ChessBoard.h
 * Author: Matěj Šimek - www.matejsimek.cz
 *
 * Created on 12. květen 2010, 22:47
 */

#ifndef _CHESSBOARD_H
#define	_CHESSBOARD_H

#include "Square.h"


class ChessBoard {
public:
    /**     
     * Create typical gameplay chessboard 8x8, 8 pawns, 1 queen, 1 knight
     */
    ChessBoard();
    ChessBoard(const ChessBoard& orig);
    /**
     * Create custom chessboard, allowing non square cases
     * @param boardWidth in Squares
     * @param boardHeight in Squares
     */
    ChessBoard(int boardWidth, int boardHeight);
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
     * Chessboard (from squares). Creates and indexing from top left corner - board[x][y]
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

    /**
     * Formated output to std::out
     */
    void printToStd();


private:
    /**
     * Allocates (2D array) memory using widht and height class variables
     * @return Success of memory alocation
     */
    bool allocateMemory();

};

#endif	/* _CHESSBOARD_H */

