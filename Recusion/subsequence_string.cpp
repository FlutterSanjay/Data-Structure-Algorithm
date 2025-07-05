// Subsequence of String using Recursion
#include<bits/stdc++.h>
using namespace std;
void printSubsequence(string str,string output,int i){
    // Base Case
    if(i>str.length()-1){
        cout << output << endl;
        return;
    }

    // Exclude Function
    printSubsequence(str, output, i + 1);

    // Include Function
    output.push_back(str[i]);
    printSubsequence(str, output, i + 1);
}

int main(){
    string str = "abc";
    string output = "";
    int i = 0;
    printSubsequence(str, output, i);
    return 0;
}