/*
*******
*     *
*******
*/

#include<iostream>
using namespace std;

int main(){

    for (int row = 0; row < 4;row++){
        if(row==0 || row==3){
            for (int col = 0; col < 5;col++){
                cout << "*  ";
            }
        }else{
            //*_space_*
            cout << "* ";
            for (int j = 0; j < 3;j++){
                cout << " ";
            }
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
