// file Handling
#include<iostream>
#include<fstream>
using namespace std;
class demo{
    public:
    char name[20];
    int age;

    void takee(){
        cout<<"Enter your Name : ";
        cin>>name;
        cout<<"Enter your Age : ";
        cin>>age;
    }

    void inputt(){
        ofstream w;
        w.open("text.txt",ios::app);
        w.write((char*)this,sizeof(*this));
        w.close();
    }
    void view(){
        ifstream r;
        r.open("text.txt",ios::in);
        if(!r) cout<<"File Not Found...";
        else{
            r.read((char*)this,sizeof(*this));
            while(!r.eof()){
                cout<<"Your Name is "<<name<<" and your Age is "<<age<<"\n";
                r.read((char*)this,sizeof(*this));
            }
        }
        r.close();
    }
};
int main(){
    demo obj;
   // obj.takee();
    //obj.inputt();
    obj.view();
    return 0;
}