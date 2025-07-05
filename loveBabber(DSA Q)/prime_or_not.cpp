// prime number or not

#include<iostream>
using namespace std;

void findPrime(int num){
    int count =0;
    if(num==1){
        cout<<"Not a Prime No";
    }else {
        for(int i=1;i<=num;i++){
            if(num % i ==0 && num>=i){
                count++;
            }
        }
        if(count == 2){
            cout<<"Prime No :"<<num<<endl;
        }else{
            cout<<"Not a Prime No"<<endl;
        }
    }
}

int main(){
    int num=10;
    findPrime(num);
    return 0;
}