#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Minesweeper.h"

class Game{

public:
    Game(int gridWidth,int gridHeight,int numberOfMines, Minesweeper minesweeper);
    std::vector<std::vector<int> > getGame();
    void setCell(int x, int y);
    bool getHasFinished();
    int isWon(); // won = true, lost = false
private:
    std::vector<std::vector<int> > game;
    Minesweeper minesweeper;
    int hasFinished = false; //Has the game finished?
    int cellsRevealed = 0; //Number of current cells revealed
    int numberOfMines;
    bool won = false;
    int gridWidth;
    int gridHeight;
    void revealAllMines();
    void clearCells(int row, int column, bool allowedClear);
};

#endif // GAME_H
