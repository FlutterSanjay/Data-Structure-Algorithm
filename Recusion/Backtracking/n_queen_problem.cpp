// N-Queen Problem
// T.C - O(n!) -> to Optimized used unordered_map ->T.C O(1);
#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>& board,int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
         cout<<endl;
    }
            cout<<endl;

}
bool isSafe(vector<vector<int>>& board,int row,int col,int n){
    // upper left Diagonal
    int i=row;
    int j=col;
    
    while(i >= 0 && j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
    
    // left Row 
    i=row;
    j=col;
    
    while(j >= 0){
        if(board[i][j]==1){
            return false;
        }
        j--;
    }
    
    // Bottom left diagonal
    i=row;
    j=col;
    
    while(i<n && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(vector<vector<int>>&board,int col,int& n){
    
    // Base Case
    if(col >= n){
        printBoard(board,n);
        return ;
    }
    
    // 1 case solve krna hoga Baki recursion shambal lega
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col] = 1;
            
            solve(board,col+1,n);
            
            board[row][col] = 0;
        }
    }
}

int main(){
    int n=4;
    vector<vector<int>>board(n,vector<int>(n,0));
    int col =0;
    solve(board,col,n);
    
    return 0;
}