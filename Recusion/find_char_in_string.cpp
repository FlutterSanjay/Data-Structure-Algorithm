// Perform searching in String
#include<bits/stdc++.h>
using namespace std;
bool findKey(string str,int n,bool &find,char key){
    // Base Case
    if(n == -1) return find;
    
    // Processing
    if(str[n]==key){
     find=true;
    }
    
    // Recursive Relation
    return findKey(str,n-1,find,key);
}

int main(){
    
    string str = "love babber";
    int n=str.size() - 1;
    bool find=false;
    char key ='s';
    bool result = findKey(str,n,find,key);
    cout<<(result?"Found":"Not Found");
    return 0;
}