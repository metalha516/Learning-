#include<bits/stdc++.h>
using namespace std;
//place N Queens on NxN chessboard so that no 2 queen can attack each other 

void printBoard(vector<vector<char>>board){
    int n = board.size();
    for(int i = 0; i<n; i++){
     for(int j = 0; j<n; j++){
       cout<<board[i][j]<<" ";
     }
     cout<<endl;
   }

   cout<<"________________"<<endl;
}


bool isSafe(vector<vector<char>>&board, int row, int col){
    int n = board.size();
    //horizontal
    for(int i = 0; i<n; i++){
        if(board[row][i] == 'Q') return false;
    }

    //vertical

    for(int i = 0; i<row; i++){
        if(board[i][col] == 'Q') return false;
    }
    
    //diagonal Left
      for(int i = row, j = col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q') return false;
      }

      //diagonal Right
       for(int i = row, j = col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q') return false;
      }
      return true;
}


void nQueens(vector<vector<char>>&board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return;
    }

    for(int i = 0; i<n; i++){
        if (isSafe(board, row, i)){
            board[row][i] = 'Q';
            nQueens(board, row+1);
            board[row][i] = '.';
        }
    }
}


int main(){
   vector<vector<char>>board;
   int n;
   cin>>n;
   for(int i = 0; i<n; i++){
     vector<char>row;
     for(int j = 0; j<n; j++){
        row.push_back('.');
     }
     board.push_back(row);
   }
   nQueens(board, 0);
}