#include<iostream>
#include<vector>
using namespace std;
 void sort(vector <int> &v){
    int low=0;
    int high=v.size()-1;
    while(low<high){
        if(low%2!=0 && high%2==0){
            swap(v[low],v[high]);
            high--;
            low++;
        }
        else if(low%2==0){
            low++;
        }
        else {
            high--;
        }

    }
    return ;
 }

 int main(){
    vector <int> v(5);
    for(int i=0;i<5;i++){
        cout<<"Enter your no:";
        cin>>v[i];
    }
    sort(v);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
 }