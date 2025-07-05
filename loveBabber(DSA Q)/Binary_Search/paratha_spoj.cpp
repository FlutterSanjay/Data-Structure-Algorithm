// Paratha Spoj 
//P (P ≤ 1000) pratas packed for the function. The stall has L cooks (L ≤ 50) and each cook has a rank R (1 ≤ R ≤ 8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata).

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>cookRank,int p,int mid){
    int currP = 0;
    for (int i = 0; i < cookRank.size();i++){

        int R = cookRank[i];
        int j = 1;
        int totalTime = 0;
        while(true){
         if(totalTime+R*j<=mid){
             totalTime += R * j;
             j++;
             currP++;
         }else{
             break;
         }
        }
        if(currP>=p){
            return true;
        }
    }
    return false;
}

int minTimeTake(vector<int>&cookRank,int p){
    int s = 0;
    int max = *max_element(cookRank.begin(), cookRank.end());
    int e = max * (p * (p + 1)) / 2;
    int ans = -1;

    while(s<=e){
        int mid = s + (e - s) / 2;
        if(isPossible(cookRank,p,mid)){
            ans = mid;
            e = mid - 1; // get the min time
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> cookRank = {1, 2, 3, 4};
    int p = 10;
    int noOFcook = 4;

    int minTime = minTimeTake(cookRank, p);
    cout << "The min Time Require to Complete the Order : " << minTime << endl;
    return 0;
}