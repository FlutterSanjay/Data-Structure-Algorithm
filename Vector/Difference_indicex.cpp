// difference of even and odd index
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int count=0,count1=0;

vector <int> v(6);
for(int i=0;i<6;i++){
    cout<<"Enter your no:";
    cin>>v[i];
}

for(int i=0;i<6;i++){
    if(i%2==0){
        count=count+v[i];
    }
    else {
        count1=count1+v[i];
    }
}
    int diff=count-count1;
    if(diff<0){
        cout<<"Difference of index: "<<-diff;
    }
    else {
        cout<<"Differece of index: "<<diff;
    }

    return 0;
}