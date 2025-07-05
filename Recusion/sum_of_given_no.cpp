// sum of given no
#include<iostream>
using namespace std;
int tsum=0;
void sum(int num){
    
    if(num==0){
    cout<<"Sum of Given no : "<<tsum;
    return ;
      }
     tsum+=num;
  return sum(num-1);
}

int main(){
    int num;
    cout<<"Enter your no : ";
    cin>>num;
    sum(num);
    return 0;

}