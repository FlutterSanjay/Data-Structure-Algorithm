// Find the large Factorial Number
#include<iostream>
#include<vector>
using namespace std;
vector<int> largeFactorial(int num){
    vector<int> ans;
    int carry=0;
    ans.push_back(1);
    for(int i=2;i<=num;i++){
        for(int j=0;j<ans.size();j++){
            int x=ans[j]*i+carry;
            ans[j]=x%10;
            carry=x/10;
        }
        // break the carry and store 
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    
    for(int i=0,j=ans.size()-1;i<j;i++,j--){
        int temp=ans[i];
        ans[i]=ans[j];
        ans[j]=temp;
        
    }
    return ans;
}
int main(){
    int num=7;
    vector<int> ans=largeFactorial(num);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}