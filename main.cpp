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

    ChessBoard * hra1 = new ChessBoard(4, 4);

    hra1->insertRandomPawns(8);

    hra1->insertRandomKnights(1);

    hra1->insertRandomQueens(1);

    hra1->printToStd();

    Queen q1(hra1->queenPositions[0].x, hra1->queenPositions[0].y, hra1);
    Knight n1(hra1->knightPositions[0].x, hra1->knightPositions[0].y, hra1);

    for (int i = 0; i < hra1->getPawnCount(); i++) {
        cout << "P" << i << ": " << hra1->pawnPositions[i].x << ", " << hra1->pawnPositions[i].y << endl;

    }




    return 0;
}

