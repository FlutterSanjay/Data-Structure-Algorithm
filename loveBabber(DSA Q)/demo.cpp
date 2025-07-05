// Selection Sort using Recurrsion
#include<iostream>
using namespace std;

int* selectionSort(int arr[],int s,int e){
    if(s==e) {
        for (int i=0; i < 5;i++){
            cout << arr[i] << endl;
        }
    }
    else{
        int minIndex;
        for(int i=s;i<e;i++){
            
            if(arr[i+1]<arr[i]){
                minIndex=i+1;
            }
            swap(arr[i],arr[minIndex]);
        }
        
        selectionSort(arr,s++,e);
    }
}
int main(){
    int arr[5];
    int num;
    for (int i = 0; i < 5;i++){
        cout << "Enter your Number:";
        cin >> num;
        arr[i] = num;
    }
        int *result = selectionSort(arr, 0, 5);
    for(int i=0;i<5;i++){
        cout<<*(result +i);
    }
    return 0;
}