//Divide Two Number using Binary Search
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int divident,int divisor){
    int s = 0;
    int e = abs(divident);
    

    int storeValue;

    while(s<=e){
        int mid = (s + e) / 2;

        if(mid * abs(divisor)<=abs(divident)){
            storeValue = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return storeValue;
}

double findPrecision(int result,int divident,int divisor){
    double ans = result;
    int precision = 2;

    double step = 0.1;
    for (int i = 0; i < precision;i++){
        for (double j = ans; j * abs(divisor) <= abs(divident);j+=step){
            ans = j;
        }
        step /= 10;
    }
        if(divident<0){
            if(divident <0 && divisor<0){
                return ans;
            }else{
                ans *= -1;
                return ans;
            }
        
    }else{
        return ans;
        }
}

int main(){ 

    // 10/2
    int divident;//10
    int divisor;//2

    cout << "Enter Your Divident :";
    cin >> divident;

    cout << "Enter Your Divisor :";
    cin >> divisor;

    
    int result = binarySearch(divident, divisor);

    double solution = findPrecision(result, divident, divisor);
    cout << "Correct Answer :" << solution;
    return 0;
}