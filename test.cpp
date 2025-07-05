// Selection Sort
#include<bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int>&arr,int n){
    int min_index = 0;
    for (int i = 0; i < n-1;i++){
        min_index = i;
        for (int j = i + 1; j < n;j++)
        {
            if(arr[min_element]>arr[j]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    return arr;
}

void printArray(vector<int> & arr,int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> arr = {1, 4, 6, -9, 0, 6};
    int size = arr.size();
    vector<int> result = selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}