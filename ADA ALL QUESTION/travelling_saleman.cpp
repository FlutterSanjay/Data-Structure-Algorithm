#include<bits/stdc++.h>
using namespace std;

class TravellingSaleman{
    protected:
        vector<vector<double>> dist;
        int n;
    public:
        TravellingSaleman(vector<vector<double>> dist) : dist(dist), n(dist.size()) {};
        //Calculate the cost of current cities using permutation
        double CalculateCost(vector<int>cities){
            double totalCost = 0;
            for (int i = 0; i < n;i++){
                totalCost += dist[cities[i]][cities[i + 1] % n];
            }
            return totalCost;
        }

        // find min cost
        double findMinCost(){
            vector<int> cities(n);
            for (int i = 0; i < n;i++){
                cities[i] = i;
            }
            double minCost = numeric_limits<double>::infinity();
            do{
                double currentCost = CalculateCost(cities);
                minCost = min(minCost, currentCost);
            } while (next_permutation(cities.begin() + 1, cities.end()));
            return minCost;
        }
};
int main(){
    vector<vector<double>> dist = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}};

    TravellingSaleman tsp(dist);
    cout << "Min Cost :" << tsp.findMinCost();
    return 0;
}