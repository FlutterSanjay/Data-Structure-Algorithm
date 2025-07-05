//Largest Number
#include<bits/stdc++.h>
using namespace std;
static bool mycmp(string a,string b){
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}
string LargestNumber(vector<int>& s){
    // convert into String
    vector<string> snum;
    for(auto t:s){
        snum.push_back(to_string(t));
    }

    // decrease using the comparision
    sort(snum.begin(), snum.end(), mycmp);
    if(snum[0]=="0")
        return "0";
    string ans = "";
    for(auto t:snum){
        ans += t;
    }
    return ans;
}

int main(){
    vector<int> s = {3, 34, 30, 9, 5};
    string result = LargestNumber(s);
    cout << "Largest Number : " << result << endl;

    return 0;
}