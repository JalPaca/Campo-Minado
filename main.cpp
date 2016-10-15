#include <iostream>
#include "Game.h"
//#include "Minesweeper.h"

using namespace std;

void printGame(vector<vector<int> > state){
    //cout << state.size() << endl;
cout << "-------------------------------------------\n";
for(int i = 0; i < state.size(); i++){
    for(int j = 0; j < state.back().size();j++){
     cout << "|" << state[i][j] << "|" << " ";
    }
    cout << endl;
}
cout << "-------------------------------------------\n";
}

#include <cstdlib>
int main(){
    int gridWidth = 3;
    int gridHeight = 5;
    int numberOfMines = 5;
    int x,y;

    Minesweeper g(gridWidth,gridHeight,numberOfMines);
    Game game(gridWidth,gridHeight,numberOfMines,g);

    do{
        system("cls");
        printGame(game.getGame());
        //printGame(g.mineBoard);
        cout << "x = -1 e y = -1 exit" << endl;
        cout << "\ncoord: \n";
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        if(x == -1 || y == -1){break;};

        game.setCell(x,y);

        system("pause");


    }while(!game.getHasFinished());
    system("cls");
    printGame(game.getGame());
    if(game.isWon()){
        cout << "venceu\n";
    }else
    {
        cout << "perdeu\n";
    }

    return 0;
}
