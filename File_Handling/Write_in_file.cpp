// Write the content in file
// File_name - text.txt;

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char string[20];
    char arr[20];
    cout<<"Enter your Content : ";
    cin>>string;
// Writing the Content in File
    ofstream write;
    write.open("text.txt");
    write<<string;
    write.close();

// Read the Content from the File
   ifstream read;
   read.open("text.txt");
   read>>(arr);
   cout<<"The Content in File :"<<arr;
   read.close();
   return 0;
}