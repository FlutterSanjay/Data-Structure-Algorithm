// Perform searching in String and return index
#include<bits/stdc++.h>
using namespace std;
int findKey(string &str,int n,char& key){
    static int index=-1;
    // Base Case
    if(n == -1) return index ;
    
    // Processing
    if(str[n]==key){
     index=n;
    }
    
    // Recursive Relation
    return findKey(str,n-1,key);
}

int main(){
    
    string str = "love babber";
    int n=str.size() - 1;
    // bool find=false;
    char key ='r';
    int result = findKey(str,n,key);
    cout<<result;
    return 0;
}