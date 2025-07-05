// Work for both 0s,1s or 0s,1s,2s
#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int> nums){
  int i=0;
        int m=0;
        int j=nums.size()-1;
        while(m<=j){
            if(nums[m]==0){
                swap(nums[i],nums[m]);
                i++,m++;
            }else if(nums[m]==1){
                m++;
            }else{
                swap(nums[m],nums[j]);
                j--;
            }
        }
    

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    vector<int> arr{0,1,1,0};
    sortArray(arr);
    return 0;
}