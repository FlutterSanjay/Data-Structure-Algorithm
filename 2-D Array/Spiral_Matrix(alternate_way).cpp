// Spiral_Matrix Printing



#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
      int top=0;
      int bottom=r-1;
      int left=0;
      int right=c-1;
    
        //move left to right
        while(top<=bottom && left<= right){
           for(int i=left;i<=right;i++)
               ans.push_back(matrix[top][i]);
           top++;
           
           // move top to bottom

        for(int i=top;i<=bottom;i++)
            ans.push_back(matrix[i][right]);
        right--;
        
        // move to left to right
        if(top<=bottom){
        for(int i=right;i>=left;i--)
            ans.push_back(matrix[bottom][i]);
        
        bottom--;
            
        }

        // move to bottom to top

        if(left<=right){
            for(int i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
                left++;
            }
            
        }
        
    return ans;
    
    }
    
    
};

