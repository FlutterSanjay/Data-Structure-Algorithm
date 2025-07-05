#include<iostream>
using namespace std;
class heap{
    public:
    int * arr;
    int size;
    int capacity;
    heap(int s){
        arr=new int[s];
        size=0;
        capacity=s;
    }
    void input(int data){
        if(size>=capacity){
            cout<<"Array is Full";
        }else{
            arr[size++]=data;
        }
    }
    
    
    void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(){
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
    for(int i=size-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
  }
}
};

int main(){
    heap h(6);
    h.input(12);
    h.input(11);
    h.input(13);
    h.input(5);
    h.input(6);
    h.input(7);
    
    h.heapSort();
    // display(ans);
    return 0;
}