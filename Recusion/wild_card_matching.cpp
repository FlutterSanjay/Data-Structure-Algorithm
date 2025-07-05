// Pattern Matching
#include<bits/stdc++.h>
using namespace std;

//T.C -> O(2^n) & S.C -> O(n)
bool isMatching(string& s,int si,string& p,int pi){
    
    // Base Case
    if(si == s.size() && pi == p.size()){
        return true;
    }
    
    if(si == s.size() && pi<p.size()){
        while(pi<p.size()){
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }
    
    // single character
    if(s[si] == p[pi] || '?' == p[pi]){
        return isMatching(s,si + 1,p,pi + 1);
    }
    
    if(p[pi] == '*'){
        
        bool caseA = isMatching(s,si + 1,p,pi);
        bool caseB = isMatching(s,si,p,pi + 1);
        return caseA || caseB;
    }
    return false;
}
int main(){
    string s = "abcdefg";
    string p = "ab?fg";
    int si=0;
    int pi=0;
    bool result = isMatching(s,si,p,pi);
    cout<<(result?"Pattern Match":"Pattern Not Match");
    return 0;
}