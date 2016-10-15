/**
 * Minesweeper header files
 * @author Stephen Liang
 * @author Aisha Halim
 * Created for CS 340 Fall 2010 - Professor Troy
 */

#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#define MINE 9

#include <vector>

class Minesweeper
{
public:
    Minesweeper();
    Minesweeper(int gridWidth, int gridHeight, int mineNumber);
    ~Minesweeper();
    bool isMine(int, int);
    int getValue(int, int);
private:
    void generateBoard();
    int mineNumber;
    int gridWidth;
    int gridHeight;
    std::vector<std::vector<int> > mineBoard; //temp

    //int gridSize;

};

#endif // MINESWEEPER_H
