// Perform searching in String
#include<bits/stdc++.h>
using namespace std;
int findKey(string &str,int n,char& key){
    static int index=0;
    // Base Case
    if(n == -1) return index ;
    
    // Processing
    if(str[n]==key){
     index+=1;
    }
    
    // Recursive Relation
    return findKey(str,n-1,key);
}

int main(){
    
    string str = "love babber";
    int n=str.size() - 1;
    // bool find=false;
    char key ='b';
    int result = findKey(str,n,key);
    cout<<result;
    return 0;
}