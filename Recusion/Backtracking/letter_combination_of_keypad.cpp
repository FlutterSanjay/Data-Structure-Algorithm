//Letter Combination of a Phone
#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans,int index,string& digit,vector<string>& mapping,string output){
    
    // Base Case
    if(index >= digit.size()){
        ans.push_back(output);
        return ;
    }
    
    // Recursion
    int dgt=digit[index] - '0';
    string value = mapping[dgt];
    
    for(int i=0;i<value.size();i++){
        char ch=value[i];
        // Include
        output.push_back(ch);
        
        // recursive call
        solve(ans,index+1,digit,mapping,output);
        
        // Backtracking
        output.pop_back();
    }
}

int main(){
    string digit="23";
    vector<string> ans;
    string output="";
    vector<string>mapping(10);
    mapping[2]="abc";
    mapping[3]="def";
    mapping[4]="ghi";
    mapping[5]="jkl";
    mapping[6]="mno";
    mapping[7]="pqrs";
    mapping[8]="tuv";
    mapping[9]="wxyz";
    int index=0;
    solve(ans,index,digit,mapping,output);
    
    for(auto i:ans){
        cout<< i<<" ";
    }
    return 0;
}