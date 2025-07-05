// print the reverse counting
#include<iostream>
using namespace std;

void count(int num){
    if(num==0) return ;

    cout<<num<<endl;
    return count(num-1);
}
int main(){
    int num;
    cout<<"Enter your no: ";
    cin>>num;
    count(num);
    return 0;

}