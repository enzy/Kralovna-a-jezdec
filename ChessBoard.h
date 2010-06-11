/* 
 * File:   ChessBoard.h
 * Author: Matěj Šimek - www.matejsimek.cz
 *
 * Created on 12. květen 2010, 22:47
 */

#ifndef _CHESSBOARD_H
#define	_CHESSBOARD_H

#include "Square.h"

/**
 * ChessBoard Class
 */
class ChessBoard {
public:
    /**     
     * Create typical gameplay chessboard 8x8, 8 pawns, 1 queen, 1 knight
     */
    ChessBoard();

    /**
     * Create custom chessboard, allowing non square cases
     * @param boardWidth in Squares
     * @param boardHeight in Squares
     */
    ChessBoard(int boardWidth, int boardHeight);

    /**
     * Desctructor, de-allocatte memory
     */
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

    /**
     * Insert to chessboard random placed pawns
     * @param pawnCountToInsert Number of pawns to insert
     */
    void insertRandomPawns(int pawnCountToInsert);

    /**
     * Insert single pawn on the specific position
     * @param x from left side
     * @param y from top side
     * @return Success of operation
     */
    bool insertPawn(int x, int y);

    /**
     * Insert to chessboard random placed knights.
     * @param knightCountToInsert Number of knights to insert
     */
    void insertRandomKnights(int knightCountToInsert);

    /**
     * Insert single knight on the specific position
     * @param x from left side
     * @param y from top side
     * @return Success of operation
     */
    bool insertKnight(int x, int y);

    /**
     * Insert to chessboard random placed queens.
     * @param queenCountToInsert Number of queens to insert
     */
    void insertRandomQueens(int queenCountToInsert);

    /**
     * Insert single queen on the specific position
     * @param x from left side
     * @param y from top side
     * @return Success of operation
     */
    bool insertQueen(int x, int y);


private:
    /**
     * Allocates (2D array) memory using widht and height class variables
     * @return Success of memory alocation
     */
    bool allocateMemory();

    int freeSquares;

};

#endif	/* _CHESSBOARD_H */

