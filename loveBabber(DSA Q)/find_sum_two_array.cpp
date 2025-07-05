#include<iostream>
#include<vector>
using namespace std;
vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        vector<int> ans;
        int i=arr1.size()-1;
        int j=arr2.size()-1;
        int carry=0;
        while(i>=0 && j>=0){
            int x=arr1[i]+arr2[j]+carry;
            int digit=x%10;
            carry=x/10;
            ans.push_back(digit);
            i--;
            j--;
        }
        while(i>=0){
            int x=arr1[i]+0+carry;
            int digit=x%10;
            carry=x/10;
            ans.push_back(digit);
            i--;
        }
        
          while(j>=0){
            int x=arr2[j]+0+carry;
            int digit=x%10;
            carry=x/10;
            ans.push_back(digit);
            j--;
        }
        if(carry){
            ans.push_back(carry);
        }
        
        // while(ans[ans.size()-1]==0){
            // ans.pop_back();
        // }
        
        // reverse(ans.begin(),ans.end());
        for(int i=0,j=ans.size()-1;i<j;i++,j--){
            int temp=ans[i];
            ans[i]=ans[j];
            ans[j]=temp;
        }
        return ans;
        
    }
int main(){
    vector<int> ans{9,0,9,4};
    vector<int> arr{2,8,4};
    vector<int> result = findSum(ans,arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
