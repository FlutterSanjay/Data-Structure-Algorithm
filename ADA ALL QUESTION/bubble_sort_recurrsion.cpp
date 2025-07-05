// Bubble Sort using recursion
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int e){
    if(e==1){
        return;
    }
    for (int i = 0; i < e - 1;i++){
        if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
    }
    bubbleSort(arr, e--);
}

int main(){
    int arr[5] = {98765};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5;i++){
        cout << arr[i]<<" ";
    }
}