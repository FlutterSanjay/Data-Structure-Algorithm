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