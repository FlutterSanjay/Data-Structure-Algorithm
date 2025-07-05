// Column-Wise N-Queen
#include<bits/stdc++.h>
using namespace std;

class ColumnWise{
    public:
    
    bool isSafe(int row,int col,vector<string>board,int n){
        
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
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
        for(int i=r,j=c;i<n && j>=0;i++,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    
    void solve(int col,vector<string>board,vector<vector<string>> & ans,int n){
        if(col>=n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
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
    
    ColumnWise c;
    vector<vector<string>> ans=c.solveNQueen(n);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}