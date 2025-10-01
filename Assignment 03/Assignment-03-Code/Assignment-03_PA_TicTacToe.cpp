#include <iostream>
#include <cmath>
using namespace std;
// https://csc340.ducta.net/ClassMeeting_PACKAGES/PKG02_CPP-Basics.pdf
// https://csc340.ducta.net/ClassMeeting_PACKAGES/PKG04_CPP_a_REFERENCE_STL-and-Iterators_aReference.pdf

bool isWon(char symbol, char boarArr[][3] ){
  //check each row
  int numRows, numCols;

  for(int i = 0; i < 3; i++){
    if(boarArr[i][0] == symbol && boarArr[i][1] == symbol && boarArr[i][2] == symbol){
      return true;
    }
  }

  //check each column
  for(int i = 0; i < 3; i++){
    if(boarArr[0][i] == symbol && boarArr[1][i] == symbol && boarArr[2][i] == symbol){
      return true;
    }
  }

  //check diagonals
  if((boarArr[0][0] == symbol && boarArr[1][1] == symbol && boarArr[2][2] == symbol) ||
     (boarArr[0][2] == symbol && boarArr[1][1] == symbol && boarArr[2][0] == symbol)    ){
      return true;
  }

  return false;
};

bool isDraw(char boarArr[][3]){
  // for(char[][3]::iterator itr = board.begin(); itr != board.end(); ++itr){
  //   if(*itr == ' '){return false;}
  // }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(boarArr[i][j] == ' '){return false;}
    }
  }
  
  // check if either person has won
  if (isWon('O', boarArr) || isWon('X', boarArr)){return false;}
  return true;
};

void displayBoard(char a[][3]){
  // draw the board row by row
  for(int i = 0; i < 3; i++){
    cout << "-------------" << endl;
    cout << "| " << a[i][0] 
         << " | " << a[i][1]
         << " | " << a[i][2] << " |" << endl;
  }
  cout << "-------------" << endl;
  return;
};

void makeAMove(char boarArr[][3], char symbol){
  bool isValid = false;
  int row, col;
  while (!isValid){
    row = rand() % 3;
    col = rand() % 3;
  
    if(boarArr[row][col] == ' '){isValid = true;}
  }

  boarArr[row][col] = symbol;
};

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {

		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);

		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
} 