// Cut Into Segment
#include<bits/stdc++.h>
using namespace std;

int cutSegement(int n,int x,int y,int z){
    //Base Case
    if( n == 0)
        return 0;
    
    if( n < 0)
        return INT_MIN;


        // Recursive Call

    int ans1 = cutSegement(n - x, x, y, z) + 1;
    int ans2 = cutSegement(n - y, x, y, z) + 1;
    int ans3 = cutSegement(n - z, x, y, z) + 1;

    int result = max(ans1, max(ans2, ans3));
    return result;
}
int main(){
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int result = cutSegement(n, x, y, z);
    if(result == INT_MIN) {
        result = 0;
    }
    cout << "Ans : " << result << endl;
    return 0;
}