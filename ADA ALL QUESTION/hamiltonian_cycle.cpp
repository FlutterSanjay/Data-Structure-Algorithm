#include<bits/stdc++.h>
using namespace std;
class HamiltonCycle{
    public:
    bool isSafe(int v ,vector<vector<int>>&graph,vector<int>&path,int pos){
        if(graph[path[pos-1]][v]==0){
            return false;
        }
    
    
    for(int i=0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
    }

bool hamCycleUtil(vector<vector<int>>&graph,vector<int>&path,int pos){
    if(pos==graph.size())
{
    return graph[path[pos-1]][path[0]] ==1;
}

for(int v=1;v<graph.size();v++){
    if(isSafe(v,graph,path,pos)){
        path[pos]=v;
        
        if(hamCycleUtil(graph,path,pos+1)){
            return true;
        }
        path[pos]=-1;
    }
}
return false;
}

bool hamCycle(vector<vector<int>>& graph,int start){
    int V = graph.size();
    vector<int> path(V,-1);
    
    path[0]=start;
    
    if(!hamCycleUtil(graph,path,1)){
        cout<<"No Hamiltonian Cycle Exists"<<endl;
        return false;
    }
    return true;
}
};
