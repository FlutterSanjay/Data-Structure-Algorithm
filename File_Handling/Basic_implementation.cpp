// Read & Write File using Code
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    // for reading the file
   string sen;
   ifstream in("text.txt");
   in>>sen;
   cout<<sen<<endl;
   // for writing file
   string s;
   cout<<"Enter your sentence : ";
   cin>>s;
   ofstream out("text.txt");
   out<<s;
   return 0;
}