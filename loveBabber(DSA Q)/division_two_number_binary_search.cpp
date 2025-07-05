// Division of two Number with precision using Binary Tree
#include<iostream>
using namespace std;

int divisionNumber(int divident,int divisor){
    if(divident==0 && divisor == 0){
        return -1;
    }
    int s=0;
    int e=abs(divident);
    int ans;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(abs(mid*divisor)==abs(divident)){
            ans=mid;
            break;
        }
        else if(abs(mid*divisor)>abs(divident)){
            e=mid-1;
            
        }else{
            ans=mid;
            s=mid+1;
        }
    }
    if((divident>0 && divisor>0) || (divident<0 && divisor<0)){
    return ans;
    }
    else{
        return -ans;
    }

}

float precisionFind(int p,int arr,int divisor,int divident){
    float ans;
    float step=0.1;
    for(int i=0;i<p;i++){
        for(float j=arr;j*divisor<=divident;j+=step){
            // cout<<j<<" ";
            ans=j;
        }
        step/=10;
    }
    return ans;
}
int main(){
    int divident=19;
    int divisor=3;
    int ans=divisionNumber(divident,divisor);
    int precision;
    cout<<"Enter the Precision do you want :";
    cin>>precision;
  cout<< precisionFind(precision,ans,divisor,divident);
    return 0;
}