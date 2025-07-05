#include<bits/stdc++.h>
using namespace std;
class LongestPalindrome{
    public:
    string s,t;
    LongestPalindrome(string & first,string &reverse):s(first),t(reverse){}
    
    int lcp(){
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m][n];
    }
};

int main(){
    string first,second;
    cout<<"Enter your String:";
    cin>>first;
    second=first;
    reverse(second.begin(),second.end());
    
    LongestPalindrome l(first,second);
    cout<<l.lcp();
    return 0;
    
}