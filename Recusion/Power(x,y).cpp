// find the power of given no x^y;
#include<iostream>
using namespace std;
int power(int b,int p){
    if(p==0) return 1;
    return b*power(b,p-1);
}

int main(){
    int b,p;
    cout<<"Enter your base no: ";
    cin>>b;

    cout<<"Enter your Power no: ";
    cin>>p;
    int result=power(b,p);
    cout<<"Power("<<b<<","<<p<<") : "<<result;
    return 0;

}
