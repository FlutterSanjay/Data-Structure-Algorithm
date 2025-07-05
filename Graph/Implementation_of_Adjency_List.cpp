// implementing the Adjacency List
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int ,list<int>> adj;
    
    void edge(int u,int v,bool direction){
        // direction = 0 -> Undirected Graph
        // direction = q -> Directed Graph
        
        //create edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of node : "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of Edges : "<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.edge(u,v,0);
    }
    //printing graph
    g.print();
    return 0;
}
    
