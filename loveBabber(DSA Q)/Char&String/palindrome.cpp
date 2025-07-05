// palindrome - 'nitin' read -left to right it same or vice versa 

#include<bits/stdc++.h>
using namespace std;

bool palindrome(char name[]){
    int len = strlen(name);
    int i = 0;
    int j = len - 1;
    while(i<=j){

        

        if(name[i] == name[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    char name[20] = "nitip";

    bool result = palindrome(name);
    cout << (result ? "Palindrome" : "Not Palindrome");

    return 0;
}