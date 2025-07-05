// Optimized N-Queen Problem
// T.C - O(1)

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> rowCheck;
unordered_map<int,int> upperLeftDiagonal;
unordered_map<int,int> bottomLeftDiagonal;


void printBoard(vector<vector<char>>& board,int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
         cout<<endl;
    }
            cout<<endl;

}
bool isSafe(vector<vector<char>>& board,int row,int col,int n){
    
    //Row Check
    
    if(rowCheck[row] == 1) return false;
    
    
    // Upper left Diagonal Check
    
    if(upperLeftDiagonal[n+1+col-row] == 1) return false;
    
    
    
    // Bottom Left Diagonal Check
    
    if(bottomLeftDiagonal[row + col] == 1) return false;
    
    // upper left Diagonal
    // int i=row;
    // int j=col;
    
    // while(i >= 0 && j>=0){
    //     if(board[i][j] == 1){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }
    
    // // left Row 
    // i=row;
    // j=col;
    
    // while(j >= 0){
    //     if(board[i][j]==1){
    //         return false;
    //     }
    //     j--;
    // }
    
    // // Bottom left diagonal
    // i=row;
    // j=col;
    
    // while(i<n && j >= 0){
    //     if(board[i][j] == 1){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    return true;
}

void solve(vector<vector<char>>&board,int col,int& n){
    
    // Base Case
    if(col >= n){
        printBoard(board,n);
        return ;
    }
    
    // 1 case solve krna hoga Baki recursion shambal lega
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 'Q';
            rowCheck[row]=1;
            upperLeftDiagonal[n+1+col-row]=1;
            bottomLeftDiagonal[row+col] = 1;
            
            
            solve(board,col+1,n);
            
            board[row][col] = '.';
            rowCheck[row]=0;
            upperLeftDiagonal[n+1+col-row]=0;
            bottomLeftDiagonal[row+col] = 0;
        }
    }
}

int main(){
    int n=9;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    int col =0;
    solve(board,col,n);
    
    return 0;
}