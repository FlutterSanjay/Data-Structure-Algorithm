// Rat in Maze
// Rat in the Maze
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int arr[3][3],int i,int j,vector<vector<bool>>&visited,int row,int col){


    // All Condition
    if((arr[i][j]==1) && (visited[i][j] == false) && (((i >= 0) && (i < row)) && ((j>=0) && (j<col)))){
        return true;
    }
    return false;
}

void solveMaze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>> & visited,vector<string>& path,string output){
    
    // Base Case (last Cell)
    if(i == row -1 && j == col-1){
        path.push_back(output);
        return;
    }
    
    // Down
    if(isSafe(arr,i+1,j,visited,row,col)){
        visited[i+1][j] = true;
        solveMaze(arr,row,col,i+1,j,visited,path,output + 'D');
        
        // backtracking
        visited[i+1][j] = false;
    }
    // Up
      if(isSafe(arr,i-1,j,visited,row,col)){
        visited[i-1][j] = true;
        solveMaze(arr,row,col,i-1,j,visited,path,output + 'U');
        
        // backtracking
        visited[i-1][j] = false;
    }
    
    // Left
    
     if(isSafe(arr,i,j-1,visited,row,col)){
        visited[i][j-1] = true;
        solveMaze(arr,row,col,i,j-1,visited,path,output + 'L');
        
        // backtracking
        visited[i][j-1] = false;
    }
    
    // Right
     if(isSafe(arr,i,j+1,visited,row,col)){
        visited[i][j+1] = true;
        solveMaze(arr,row,col,i,j+1,visited,path,output + 'R');
        
        // backtracking
        visited[i][j+1] = false;
    }
    
    
}

int main(){
    int maze[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };
    
    if( maze[0][0] == 0){
        cout << "No Path Exist";
        return 0;
    }
    int row = 3;
    int col = 3;
    
    vector<vector<bool>> visited (row,vector<bool>(col,false)); // All Row & Column are mark as False

    visited[0][0] = true;
    vector<string> path;
    string output = "";
    
     solveMaze(maze,row,col,0,0,visited,path,output);
     
     cout<<"Printing the Result"<<endl;
     
     if(path.size() == 0){
         cout << "No Path Exist";
         return 0;
     }
     for(auto i:path){
         cout<<i<<" ";
     }
     cout<< endl;
    
    return 0;
}