// Remove all the Occurence of SubStr

#include<bits/stdc++.h>
using namespace std;

string removeAllOccurence(string s,string part){
    int len = part.size();
    
    while( s.find(part)!=string::npos){
        int val =  s.find(part);
        s.erase(val,len);
    }
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    
    string result = removeAllOccurence(s,part);
    cout<<result<<endl;
    return 0;
}