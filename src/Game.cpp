#include "Game.h"

Game::Game(int gridWidth,int gridHeight,int numberOfMines, Minesweeper minesweeper){

    this->gridHeight = gridHeight;
    this->gridWidth = gridWidth;

    this->numberOfMines = numberOfMines;
    this->minesweeper = minesweeper;

    std::vector<std::vector<int> > game;
    this->game.resize(gridHeight);
    for (int i = 0; i < gridHeight; ++i)
        this->game[i].resize(gridWidth);

    for(int i = 0; i < gridHeight; i++){
        for(int j = 0; j < gridWidth; j++)
        {
            this->game[i][j] = -1;
        }
    }
}

std::vector<std::vector<int> > Game::getGame(){
    return this->game;
}
void Game::clearCells(int row, int column, bool allowedClear){

    if(minesweeper.getValue (row, column) != MINE && allowedClear == true && this->game[row][column] == -1){

        this->game[row][column] = minesweeper.getValue(row,column);
        this->cellsRevealed++;

        if(cellsRevealed == ((gridWidth)*(gridHeight) - numberOfMines) && !minesweeper.isMine(row, column))
        {
            this->game[row][column] = minesweeper.getValue(row,column);
            revealAllMines();
            this->hasFinished = true;
            this->won = true;
            return;
        }
        //Make sure that we are allowed to clear
        if ( minesweeper.getValue (row, column) == 0)
            allowedClear = true;
        else
            allowedClear = false;

        //Recrusively call clear on all adjacent cells
        //Top left
        if ( (row-1) != -1 && (column -1) != -1)
            this->clearCells(row-1, column-1, allowedClear);
        //Top center
        if ( (row-1) != -1)
            this->clearCells(row-1, column, allowedClear);
        //Top right
        if ( (row-1) != -1 && (column + 1) != gridWidth)
            this->clearCells(row-1, column+1, allowedClear);
        //Left
        if ( (column -1) != -1)
            this->clearCells(row, column-1, allowedClear);
        //Right
        if ( (column + 1) != gridWidth)
            this->clearCells(row, column+1, allowedClear);
        //Bottom left
        if ( (row+1) != gridHeight && (column -1) != -1)
            this->clearCells(row+1, column-1, allowedClear);
        //Bottom center
        if ( (row+1) != gridHeight)
            this->clearCells(row+1, column, allowedClear);
        //Bottom right
        if ( (row+1) != gridHeight && (column+1) != gridWidth)
            this->clearCells(row+1, column+1, allowedClear);
    }
}

void Game::setCell(int row,int column){

    if((row < 0 && row > gridHeight) || (column < 0 && column > gridWidth)){
        return;
    }
    if (hasFinished)
    {
        revealAllMines();
        return;
    }
    else
    {
        this->cellsRevealed++;
    }

    if(cellsRevealed == ((gridHeight)*(gridWidth) - numberOfMines) && !minesweeper.isMine(row, column))
    {
        this->game[row][column] = minesweeper.getValue(row,column);
        revealAllMines();
        this->hasFinished = true;
        this->won = true;
        this->cellsRevealed++;
    }
    if ( minesweeper.getValue (row, column) == 0 ) {
        this->cellsRevealed--;
        this->clearCells(row, column, true);
    }
    if ( minesweeper.isMine( row, column ) )
    {
        this->game[row][column] = minesweeper.getValue(row,column);
        this->cellsRevealed--;
        revealAllMines();
        this->hasFinished = true;
    }
    this->game[row][column] = minesweeper.getValue(row,column);
}

void Game::revealAllMines(){
 //Go through all the cells and reveal all the mines
    for ( int i = 0; i < gridHeight; i++ )
    {
        for ( int j = 0; j < gridWidth; j++ )
        {
            //Check if it's a mine, if it is.. show it!
            if (minesweeper.getValue (i,j) == 9 )
            {
                this->game[i][j] = minesweeper.getValue (i,j);
            }

        }
    }
}

bool Game::getHasFinished(){
    return this->hasFinished;
}

int Game::isWon(){
    return this->won;
}
