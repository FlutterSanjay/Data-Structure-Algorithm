// Convert the Character to Upper case

#include<bits/stdc++.h>
using namespace std;
void upperCase(char name[]){
    int len = strlen(name);
    for (int i = 0; i < len;i++){
        name[i] -=  32; // or name[i]=name[i]-'a'+'A'; 
    }
}
int main(){
    char name[20] = "sanjay";

    upperCase(name);
    cout << name;
    return 0;
}