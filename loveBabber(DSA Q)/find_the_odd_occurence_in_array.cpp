// find the odd Occurence of element in array
#include<iostream>
#include<vector>
using namespace std;
int findOddOccurence(vector<int> arr){
    int s=0;
    int e=arr.size();
    while(s<=e){
        int mid=s+(e-s)/2;
        // case 1-> if Single value have
        if(s==e){
            return s;
        }
    // case 2-> if the mid is even
    if(mid%2==0){
        if(arr[mid]==arr[mid+1]){
            s=mid+2;
        }else{
            e=mid;
        }
    }
    // case 3-> if the mid is odd
    else{
        if(arr[mid]==arr[mid-1]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    }
    return -1;
}
int main(){
    vector<int> arr{1,1,2,2,3,3,4,4,5,5,3,600,600,4,4};
    int ans=findOddOccurence(arr);
    cout << "The Index value :" << ans << endl;
    cout << "The value of Index : " << arr[ans];
    return 0;
}