#include<bits/stdc++.h>
using namespace std;

void print(int board[9][9]){
    int n = 9;
    for(int i = 0; i<n; i++){
     for(int j = 0; j<n; j++){
       cout<<board[i][j]<<" ";
     }
     cout<<endl;
   }
}

bool isSafe(int sudoku[9][9], int row, int col, char digit){
    //vertical
    for(int i = 0; i<=8; i++){
        if (sudoku[i][col] == digit){
            return false;
        }
    }
    //horizontal
    for(int i = 0; i<=8; i++){
        if (sudoku[row][i] == digit){
            return false;
        }
    }
    
    //3x3 grid
    int startrow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i = startrow; i<=startrow+2; i++){
        for (int j = startCol; j<=startCol+2; j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}


bool sudokuSolver(int sudoku[9][9], int row, int col){
    if(row == 9){
        print(sudoku);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(col+1 == 9){
        int nextRow = row+1;
        int nextCol = 0;
    }
    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for(int digit = '1'; digit<='9'; digit++){
        if(isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}


int main(){
    int board[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9; j++){
            cin>>board[i][j];
        }
    }


}