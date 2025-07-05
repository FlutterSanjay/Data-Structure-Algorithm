// find the sqauere root with decimal no

#include<iostream>
using namespace std;
// for square root of given no..
int binary(int x){
    int low=0;
    int high=x;
    int ans=-1;
    while(low<=high){
        long long int mid=low+(high-low)/2;
        long long int square=mid*mid;
        if(square==x){
            return ans;
        }
        else if(square<x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
// for decimal part of square root no
double root(int x,int result){
    double fact=1;
    double ans=result;
    for(int i=0;i<3;i++){
        fact=fact/10;
        for(double j=ans;j*j<x;j=j+fact){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int x;
    cout<<"Enter your no:";
    cin>>x;
    // calling part
    int result=binary(x);
    cout<<"Square root : "<<root(x,result);
    return 0;
}