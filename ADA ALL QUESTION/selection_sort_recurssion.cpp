// Selection sort using Recurssion

#include<iostream>
using namespace std;

void selectionSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }

    int minIndex = s;
    for (int i = s; i < e;i++){
        if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
    }
    swap(arr[s], arr[minIndex]);
    selectionSort(arr, s + 1, e);
}

int main(){
    int arr[5] = {0, 3, 1, -1, 4};
    selectionSort(arr, 0, 5);
    for (int i = 0; i < 5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}