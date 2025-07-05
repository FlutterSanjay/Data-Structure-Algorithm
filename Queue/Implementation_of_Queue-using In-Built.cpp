//Implementatio of Queue using in built Function

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    int del,data,var;
    cout<<"1-Insert Element\n2-Delete Element\n3-Show the Front Element\nEnter your choice :";
    cin>>var;
     switch(var){
         case 1: 
               cout<<"Enter your no to insert in Queue ; ";
               cin>>del;
               for(int i=0;i<del;i++){
                   cout<<"Enter your no : ";
                   cin>>data;
                   q.push(data);
               }
        case 2:
               if(q.size()==0){
                    cout<<"Queue is Empty...";
                    break;
                    }

               cout<<"How many no want to delete from Queue : ";
               cin>>del;

               for(int i=0;i<del;i++){
                   q.pop();
                }
        case 3:
               if(q.size()==0){
                cout<<"Queue is Empty...";
                break;
               }
               cout<<"Top Most Elment in Queue :"<<q.front()<<endl;
         
     }
     
     return 0;
}