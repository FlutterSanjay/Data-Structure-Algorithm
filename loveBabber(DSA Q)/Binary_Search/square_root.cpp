// Square root of number with floating point

#include<bits/stdc++.h>
using namespace std;

class SquareRoot{
    public:

    int binarySearch(vector<int> arr,int low){
        int s = low;
        int e = arr.size() - 1;

        int target = arr[e];

        int storeIntegerPart;

        while(s<=e){
            int mid = (arr[e] + arr[s]) / 2;

            if(mid*mid>target){
                e = arr[mid - 1];
            }else if(mid * mid <=target){
                storeIntegerPart = mid;
                s = arr[mid + 1];
            }
        }
        return storeIntegerPart;
    }

    double findPrecision(int ans,int target){
        double finalAns = ans;
        int precision=3;
        // cout << "Enter your Precision :";
        // cin >> precision;

        double step = 0.1;

        for (int i = 0; i < precision;i++){
            for (double j = finalAns; j * j <= target;j+=step){
                finalAns = j;
            }
            step /= 10;
        }
        return finalAns;
    }
    
};
int main(){
    SquareRoot s;
    int n;
    cout << "Enter your number:";
    cin >> n;

    vector<int> arr;
    for (int i = 0; i <= n;i++){
        arr.push_back(i);
    }

    int result = s.binarySearch(arr, 0);
    double finalAns = s.findPrecision(result, n);
    cout << "The Square Root of Given Number :" << finalAns;
    return 0;
}
