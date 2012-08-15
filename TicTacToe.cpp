/*
Program: Tic-Tac-Toe
Programmer: Dominque Terry
Description: Creates a multi-dimensional array to play tic-tac-toe.
             User will choose a number between 0 and 3 to pst a move.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class TicTacToe{
         private:
                char theBoard [3][3];
         public:
                TicTacToe(void);
                void playOneGame(void);
                void switchPlayer(char &);
                void showBoard(void);
                void postMove(int, int, char);
                char determineWinner(void);
};

int main (void){
        //test the class by playing one game
        TicTacToe Game1;
        Game1.playOneGame();
}

void TicTacToe::playOneGame(void){
      //start a game and play until someone wins or a draw occurs...
      const int MaxMoves = 9;
      char currentPlayer = 'O';
      int row = 0;
      int clmn = 0;
      char theWinner = ' ';
      int nmbrOfMoves = 0; //keep track of the number of moves max is 9
	  

      do {
            switchPlayer(currentPlayer); //change player from x to o or vice versa                
            showBoard();           

            cout << "\n\nPlayer " << currentPlayer << endl; //get the players move 
            cout << "enter your row: ";
            cin >> row;
            cout << "enter your column: ";
            cin >> clmn; 

            postMove(row, clmn, currentPlayer); //post the move to the board      
            theWinner = determineWinner();  //see if anyone won the game
            nmbrOfMoves++;  //keep track of the number of moves

      } while ((theWinner == 'D') && (nmbrOfMoves < MaxMoves));

       showBoard(); //show the ending board

       if (theWinner != 'D')  //declare a winner
            cout << "\n\nThe Winner is player " << theWinner << endl;
       else
            cout << "\n\nThe Game was a Draw";
}

TicTacToe::TicTacToe(void)
{
          //intialize the array contents
for(int row =0; row < 3; row++)
	{
	
		for(int column=0; column< 3; column++)
		{
			theBoard[row][column] = ' ';
		}
	
	}

}


void TicTacToe::switchPlayer(char &currentPlayer)
{
	if(currentPlayer == 'O')
	{
		currentPlayer = 'X';
	}
	else if(currentPlayer =='X')
	{
		currentPlayer = 'O';
	}
}

void TicTacToe::showBoard()
{
        //displays the board
	for(int row =0; row < 3; row++)
	{
	
		for(int column=0; column< 3; column++)
		{
			cout << "[" << theBoard[row][column] << "]";
		}
		cout << endl;
	}

}

void TicTacToe::postMove(int row, int col, char value)
{
       //gets the users move and posts it to the board

	theBoard[row][col] = value;
}

char TicTacToe::determineWinner(void){
      //analyzes the board to see if there is a winner
      //returns a X, O indicating the winner
      //if the game is a draw then D is returned

      //check the rows
      for (int i = 0; i < 3; i++){
            if (theBoard[i][0] == theBoard[i][1]
                 && theBoard[i][1] == theBoard[i][2]
                 && theBoard[i][0] != ' '){
                 return theBoard[i][0];
            }
      }

      //check the clmns
      for (int i = 0; i < 3; i++){
             if (theBoard[0][i] == theBoard[1][i]
                   && theBoard[1][i] == theBoard[2][i]
                   && theBoard[0][i] != ' '){
                   return theBoard[0][i];
             }
       }

       //check the diagnals
       if (theBoard[0][0] == theBoard[1][1]
              && theBoard[1][1] == theBoard[2][2]
              && theBoard[0][0] != ' ') {
              return theBoard[0][0];
       }

       if (theBoard[2][0] == theBoard[1][1]
               && theBoard[1][1] == theBoard[0][2]
               && theBoard[2][0] != ' ') {
               return theBoard[2][0];
       }

       return 'D';
}