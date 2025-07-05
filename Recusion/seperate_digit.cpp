// Seperate the digit
#include<bits/stdc++.h>
using namespace std;
void seperateDigit(int num){
    //Base Case
    if(num == 0) return;
        
   // Recursive Relation
    seperateDigit(num/10);
    
    // Processing
    int mod = num % 10;
     cout<<mod <<" ";

}
int main(){
    int num=10;
   if(num==0) cout<<num;
   else seperateDigit(num);
    return 0;
}