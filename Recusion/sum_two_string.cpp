// Sum of Two Number
#include<bits/stdc++.h>
using namespace std;
void sumTwoNumber(string& num1,string& num2,int p1,int p2,string& ans,int carry=0){
    
    // Base Case
    if(p1 <0 && p2 < 0){
        if( carry != 0){
            ans.push_back(carry + '0');
        }
        return;
    }
    
    // Processing
    
    int n1 = ( p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = ( p2 >= 0 ? num2[p2] : '0') - '0';
    int csum = n1 + n2 + carry;
    carry = csum / 10;
    int digit = csum % 10;
    ans.push_back(digit + '0');
    
    // recursive relation
    sumTwoNumber(num1,num2,p1 - 1,p2 - 1,ans,carry);
}

int main(){
    string num1="99";
    string num2 = "99";
    string ans="";
    int p1=num1.size()-1;
    int p2=num2.size()-1;
    sumTwoNumber(num1,num2,p1,p2,ans);
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}