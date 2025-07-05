//Longest Common subString
#include <bits/stdc++.h>
using namespace std;

class LongestCommonSubstring{
  private:
    string str1;
    string str2;
      public:
    LongestCommonSubstring(string &text1,string & text2):str1(text1),str2(text2){}
    
    int lcs(){
        int m=str1.size();
        int n=str2.size();
        
       vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
           
        }
         return ans;
    }
};

int main(){
    string text;
    string text2;
    cout<<"Enter your String :";
    cin>>text;
    cout<<"Enter your SubString :";
    cin>>text2;
    LongestCommonSubstring l(text,text2);
    cout<<l.lcs();
    return 0;
}