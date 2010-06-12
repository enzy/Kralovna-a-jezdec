/* 
 * File:   Position.h
 * Author: Enzy
 *
 * Created on 12. červen 2010, 17:19
 */

#ifndef POSITION_H
#define	POSITION_H

class Position {
public:
    /**
     * Zero position [0, 0]
     */
    Position();

    /**
     * Custom position [x, y]
     * @param x
     * @param y
     */
    Position(int x, int y);

    /**
     * Copy constructor
     * @param orig
     */
    Position(const Position& orig);

    int x;
    int y;
private:

};

#endif	/* POSITION_H */

