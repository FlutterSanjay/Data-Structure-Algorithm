// 2D Matrix -Binary Search
#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<vector<int>> arr,int row,int col,int target){
    int s = 0;
    int e = (row * col) - 1;

    while(s<=e){
        int mid = (s + e) / 2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int midElement = arr[rowIndex][colIndex];
        if(midElement==target)
            return true;

        if(midElement<target){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return false;
}

int main(){

    int row = 3;
    int col = 3;

    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 8;
    bool result = binarySearch(arr, row, col, target);
    cout << (result ? "Data Found!" : "Data Not Found!");
    return 0;
}