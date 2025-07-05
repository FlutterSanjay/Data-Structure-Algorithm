//28. Find the Index of the First Occurrence in a String
/*
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
else return -1;
*/

// Method -1
// #include<bits/stdc++.h>
// using namespace std;
// int findFirstOccurene(string &s,string & n){
//     if(s.find(n)==string::npos){
//         return -1;
//     }
//     return s.find(n);
// }

// int main(){
//     string haystack = "sadbutsad";
//     string neddle = "sad";
//     int result = findFirstOccurene(haystack, neddle);
//     cout << "Found At Index : " << result << endl;

//     return 0;
// }

// Method -2
#include<bits/stdc++.h>
using namespace std;
int findFirstOccurence(string &s,string &ned){
    int n = s.size();
    int m = ned.size();
    for (int i = 0; i <= n-m;i++){
        for (int j = 0; j < m;j++){
            if(ned[j] != s[i+j]){
                break;
            }
            if(j==m-1){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    string s = "sadbutsad";
    string n = "sad";
    int result = findFirstOccurence(s, n);
    cout << "First Occurence : " << result << endl;

    return 0;
}