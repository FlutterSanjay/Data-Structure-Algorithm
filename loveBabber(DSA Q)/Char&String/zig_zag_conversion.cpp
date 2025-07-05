// Zig_Zag Conversion
#include<bits/stdc++.h>
using namespace std;
string zigZagConversion(string& s,int numRow){
    if(numRow==1)
        return s;

    int i = 0;
    int row = 0;
    bool direction = 1;
    vector<string> zigzag(numRow);

    while(true){
        if(direction){
            while(row<numRow && i<s.size()){
                zigzag[row++].push_back(s[i++]);
            }
            row = numRow - 2;
        }else{
            while(row>=0 && i<s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i>=s.size())
            break;
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < zigzag.size();i++){
        ans += zigzag[i];
    }
    return ans;
}

int main(){
    string s = "ABCDEFG";
    int numRow = 3;
    string result = zigZagConversion(s, numRow);
    cout << result << endl;

    return 0;
}