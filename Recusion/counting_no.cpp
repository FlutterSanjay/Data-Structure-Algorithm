// counting the no
#include<iostream>
using namespace std;
void count(int num,int x=1){ // use of default argument
    if(x>num) return ;
    cout<<x<<endl;
    return count(num,x+1);
}

int main(){
    int num;
    cout<<"Enter your no :";
    cin>>num;
    count(num);
    return 0;
}