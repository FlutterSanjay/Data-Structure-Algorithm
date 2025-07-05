// implement prime algorithm using priority_queue
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
typedef pair<int, int> pi;

class primeAlgorithm{
    private:
        int v;
        vector<vector<pi>> adj;
        public:
        primeAlgorithm(int v):v(v),adj(v){}
        
        void addEdge(int u,int v,int w){
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});

        }

        void algorithm(){
            priority_queue<pi, vector<pi>, greater<pi>> pq;

            vector<int> minWeight(v, INT_MAX);
            vector<bool> inMst(v, false);

            minWeight[0] = 0;
            pq.push({0, 0});

            int totalWeight = 0;
            while(!pq.empty()){
                int u = pq.top().second;
                int weight = pq.top().first;
                pq.pop();

                if(inMst[u]) continue;

                inMst[u] = true;
                totalWeight += weight;

                for(auto edge:adj[u]){
                    int v = edge.first;
                    int w = edge.second;

                    if(!inMst[v] && w<minWeight[v]){
                        minWeight[v] = w;
                        pq.push({w, v});
                    }
                }
            }
            cout << "Total Weight in Mst :" << totalWeight << endl;
        }
};
int main(){
    int v = 5;
    primeAlgorithm g(v);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.algorithm();

    return 0;

}