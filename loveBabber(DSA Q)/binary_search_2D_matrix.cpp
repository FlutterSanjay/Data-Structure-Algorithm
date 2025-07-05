// Implement the Binary Search in 2D Matrix
#include<iostream>
#include<vector>
using namespace std;

bool searchBin(vector<vector<int>> arr,int key){
    int m = arr.size();
    int n = arr[0].size();
    int s = 0;
    int e = m * n - 1;
 
    while(s<=e){
        int mid = s + (e - s) / 2;
        int row = mid / n; // rowIndex
        int col = mid % n;//colIndex
        int element = arr[row][col];
        if(element == key){
            return true;
        }else if(element>key){
            e = mid - 1;
        }else {
            s = mid + 1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr{{1, 3, 5}, {3, 6, 7}, {9, 3, 5}};
    cout << searchBin(arr,3);
    return 0;
}