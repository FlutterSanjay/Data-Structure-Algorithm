#include<bits/stdc++.h>
using namespace std;

class Solution{
    protected:
    string a;
    string b;
    public:
    Solution(string text1,string text2):a(text1),b(text2){}
    
    
    int solve(int i,int j,vector<vector<int>>dp){
        if(i== a.length()) return 0;
        if(j== b.length()) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans=0;
        if(a[i]==b[j]){
            ans= 1+ solve(i+1,j+1,dp);
        }
        else{
            ans=max(solve(i+1,j,dp),solve(i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    
    int lcs(){
        vector<vector<int>> dp(a.length(),vector<int>(b.length(),-1));
        return solve(0,0,dp);
    }
};

int main(){
    string a="bcdaacd";
    string b="acdbac";
    
    Solution d(a,b);
    cout<<d.lcs();
    return 0;
}