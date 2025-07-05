// add N number from user
#include<iostream>
using namespace std;

void addNNum(int num){

    int sum = 0;
    int valueStore;
    for (int i = 0; i < num;i++){
        cout << "Enter your No :";
        cin >> valueStore;
        sum += valueStore;
    }
    cout << "Sum of Number :" << sum << endl;
}

int main(){
    int num = 4;
    addNNum(num);
    return 0;
}