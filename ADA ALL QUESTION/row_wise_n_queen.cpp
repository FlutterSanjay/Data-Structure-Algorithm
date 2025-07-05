// Row-Wise N-Queen
#include<bits/stdc++.h>
using namespace std;

class RowWise{
    public:
    bool isSafe(int row,int col,vector<string>board,int n){
        
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        
        int r=row;
        int c=col;
        
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        
        r=row;
        c=col;
        
        for(int i=r,j=c;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
            
        }
        return true;
    }
    
    void solve(int row,vector<string>board,vector<vector<string>> &ans,int n){
        if(row>=n){
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n;j++){
        if(isSafe(row,j,board,n)){
            board[row][j]='Q';
            solve(row+1,board,ans,n);
            board[row][j]='.';
        }
        }
    }
    
    vector<vector<string>> solveNQueen(int n){
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};

int main(){
     int n=4;
    
    RowWise c;
    vector<vector<string>> ans=c.solveNQueen(n);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}