/* 
 * File:   main.cpp - Královna a jezdec
 * Author: Matěj Šimek - www.matejsimek.cz
 *
 * Created on 12. květen 2010, 22:31
 *
 * Zadání:
 * 19. Královna a jezdec (ML)
 * V jazyce C++ implementujte problém „Královna a jezdec“. Je zadána šachovnice
 * (může být různě veliká), na které je nějaké množství pěšců, královna a jezdec.
 * Královna a jezdec se střídají v tazích a snaží se v co nejmenším počtu tahů
 * sebrat všechny pěšce.
 *
 * Pokyny pro odevzdání:
 * https://edux.fit.cvut.cz/courses/BI-PA2/teacher/vranyj1/sp_pokyny
 */

#include <cstdlib>
#include <iostream>

#include "ChessBoard.h"
#include "Queen.h"
#include "Knight.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    // inicialization

    // automaticky nebo rucni mod?

    // rucni mod - sirka, vyska; pocet pescu; umisteni;

    ChessBoard * hra1 = new ChessBoard(5, 5);

    hra1->insertRandomPawns(5);

    hra1->insertRandomKnights(1);

    hra1->insertRandomQueens(1);

    cout << "Initial setup" << endl;
    hra1->printToStd();
    cout << endl;


    Queen q1(hra1->queenPositions[0].x, hra1->queenPositions[0].y, hra1);
    Knight n1(hra1->knightPositions[0].x, hra1->knightPositions[0].y, hra1);

    for (int i = 0; i < hra1->getPawnCount(); i++) {
        //cout << "P" << i << ": " << hra1->pawnPositions[i].x << ", " << hra1->pawnPositions[i].y << endl;
    }

    int moveCount = 1;

    while (hra1->getPawnCount() > 0) {        
        // Switch Queen and Knight in play, Queen first.
        // if (moveCount % 2 != 0) {
        // Compute Queen next move
        Position queenNextMove = q1.findNextMove();
        hra1->capturePiece(queenNextMove);
        // Make Queen move
        hra1->movePiece(q1.getCurrentPosition(), queenNextMove);
        q1.setPosition(queenNextMove);
        // } else{ // TODO: Knight move }
        cout << "\nMove #" << moveCount++ << endl;
        
        // Print movement
        hra1->printToStd();
        cout << endl;
    }

    cout << "\nThe game is on the end. Thank you for watching." << endl;



    return 0;
}

