// Remove all Occurence 
#include<bits/stdc++.h>
using namespace std;
void removeAllOccurence(string& s,string& p){
    int found = s.find(p);
    // Base Case
    if(s.find(p) != string::npos){
        string left_part = s.substr(0,found);
        string right_part = s.substr(found+p.size(),s.size());
        s=left_part + right_part;
        
        removeAllOccurence(s,p);
    }
    return;
}


int main(){
    
    string s="axxxxyyyyb";
    string part = "xy";
    removeAllOccurence(s,part);
    cout<<s<<endl;
    return 0;
}