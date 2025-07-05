// Permutation of Given String
#include<bits/stdc++.h>
using namespace std;
void permutation(string str,int i){
    // Base Case
    if(i >= str.size()){
        cout << str << " ";
        return;
    }

    // Processing
    for (int j = i; j < str.size();j++){
        swap(str[i], str[j]);

        // Recursive Solution
        permutation(str, i + 1);

        // Backtracking
        swap(str[i], str[j]);
    }
}
int main(){
    string str = "abc";
    int i = 0;
    permutation(str, i);

    return 0;
}