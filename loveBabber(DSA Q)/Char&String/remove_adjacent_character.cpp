// Remove the Adjacent Character from the given string
#include<bits/stdc++.h>
using namespace std;

string removeAdjacent(string name){
    int i = 0;
    string ans = "";
    

    int len = name.length();

    while(i<len){
         int j = ans.size();
        if(j>0){ //element hai ans mai
            if(ans[j-1]==name[i]){
                ans.pop_back();
            }else{
                ans.push_back(name[i]);
            }
        }else{
            ans.push_back(name[i]);
        }
        i++;
    }
    return ans;
}

int main(){
    string name = "abbaca";

    string result = removeAdjacent(name);
    cout << result << endl;
    return 0;
}