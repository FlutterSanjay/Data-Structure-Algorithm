// wave printing
#include<iostream>
#include<vector>
using namespace std;

void wavePrinting(vector<vector<int>> arr){
    cout<<"Size of Col :"<<arr[0].size()<<endl;
    cout<<"Size of Row :"<<arr.size()<<endl;
    for(int col=0;col<arr[0].size();col++){
        if(col%2==0){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i][col]<<" ";
            }
        }else{
            for(int i=0;i<arr.size();i++){
                cout<<arr[i][col]<<" ";
            }
        }
    }

    }
int main(){
    vector<vector<int> > arr {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    wavePrinting(arr);
    
    return 0;
}