// Distributed Repeating Integer
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& count,vector<int>& quantity,int iCustomer){

    // Base Case
    if(iCustomer >= quantity.size()){
        return true;
    }

    for (int i = 0; i < count.size();i++){
        if(count[i] >= quantity[iCustomer]){
            count[i] -= quantity[iCustomer];
            if(solve(count,quantity,iCustomer+1)){
                return true;
            }

            // Backtrack
            count[i] += quantity[iCustomer];
        }


    }
    return false;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3, 3};
    vector<int> quantity = {2, 2, 3};

    unordered_map<int, int> countMap;
    for(auto i:arr){
        countMap[i]++;
    }

    vector<int> count;

    for(auto i:countMap){
        count.push_back(i.second);
    }

// Sort the Quantity in Descending Order

    sort(quantity.rbegin(), quantity.rend());
    bool result = solve(count, quantity, 0);
    cout << result << endl;

    return 0;
}