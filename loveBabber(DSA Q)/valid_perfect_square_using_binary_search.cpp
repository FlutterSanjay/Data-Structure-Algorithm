// Valid Perfect square;
#include<iostream>
using namespace std;

int validPerfectSquare(int n){
    int target=n;
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid==target){
            ans=mid;
            return ans;
        }else if(mid*mid>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int num=25;
    cout<<validPerfectSquare(num);
    return 0;
}