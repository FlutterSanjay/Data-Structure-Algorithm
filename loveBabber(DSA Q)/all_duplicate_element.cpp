// find the duplicate element
#include<iostream>
#include<vector>
using namespace std;

 vector<int> findDuplicate(vector<int> arr) {
        int result=-1;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int index=abs(arr[i]);
            if(arr[index]<0){
                result=index;
                ans.push_back(result);
            }
            else{
                arr[index]*=-1;
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
            return ans;
        }else{
        
    return ans;
        }
    }

int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> ans=findDuplicate(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}