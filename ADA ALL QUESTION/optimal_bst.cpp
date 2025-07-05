// #include<bits/stdc++.h>
// using namespace std;

// class OptimalBST{
//     private:
//     int* keys;
//     int* freq;
//     int n;
    
//     int sum(int i,int j){
//         int s =0;
//         for(int k=i;k<=j;k++)
//             s+=freq[k];
//             return s;
        
//     }
    
//     public:
//     OptimalBST(int keys[],int freq[],int n){
//         this->keys=keys;
//         this->freq=freq;
//         this->n=n;
//     }
    
//     int optimalSearchTree(){
//         int cost[n][n];
        
//         for(int i=0;i<n;i++)
//             cost[i][i]=freq[i];
        
//         for(int l=2;l<=n;l++){
//             for(int i=0;i<=n-l;i++){
//                 int j=i+l;
//                 cost[i][j]=INT_MAX;
//                 int off_set_sum = sum(i,j);
                
//                 for(int r=i;r<=j;r++){
//                     int c = ((r>i)? cost[i][r-1]:0) + ((r<j)? cost[r+1][j]:0)+off_set_sum;
                    
//                     if(c<cost[i][j])
//                     cost[i][j] = c;
//                 }
//             }
//         }
//         return cost[0][n-1];
//     }
// };
// int main(){
//     int keys[] = {10,12,20};
//     int freq[]={34,8,50};
//     int n = sizeof(keys)/sizeof(keys[0]);
    
//     OptimalBST ob(keys,freq,n);
//     cout<<"Cost of Optimal BST is "<<ob.optimalSearchTree()<<endl;
//     return 0;
// }


 #include<bits/stdc++.h>
using namespace std;
class Item{
    public:
    int key;
    int frequency;
    
    Item(int k,int f):key(k),frequency(f){}
};

class OptimalBST{
    private:
    vector<Item>items;
    int n;
    vector<vector<int>>cost;
    vector<vector<int>>root;
    public:
    OptimalBST(vector<Item> items):items(items){
        
        n=items.size();
        cost.resize(n+1,vector<int>(n+1,0));
        root.resize(n+1,vector<int>(n+1,0));
        
        calculateOptimalBST();
    }
    
    void printOptimalCost(){
        cout<<"Optimal Cost:"<<cost[1][n]<<endl;
    }
    
    void printOptimalStructure(){
        cout<<"Optimal BST Structure (Root):"<<endl;
        printTree(1,n);
    }
    
    void calculateOptimalBST(){
        for(int i=1;i<=n;++i){
            cost[i][i]=items[i-1].frequency;
            root[i][i]=i;
        }
        for(int len=2;len<=n;++len){
            for(int i=1;i<=n-len+1;++i){
                int j=i+len-1;
                cost[i][j]=INT_MAX;
                
                for(int r=i;r<=j;++r){
                    int c=(r>i?cost[i][r-1]:0)+(r<j?cost[r+1][j]:0)+sumFrequency(i,j);
                    
                    if(c<cost[i][j]){
                        cost[i][j] =c ;
                        root[i][j] =r;
                    }
                }
            }
            
        }
    }
    
    int sumFrequency(int i,int j){
        int sum=0;
        for(int k=i;k<=j;++k){
            sum+=items[k-1].frequency;
        }
        return sum;
    }
    
    void printTree(int i,int j){
        if(i>j) return ;
        
        int r=root[i][j];
        cout<<"Keys:"<<items[r-1].key<<"(Root of subtree["<<i<<","<<j<<"])"<<endl;
        
        printTree(i,r-1);
        printTree(r+1,j);
    }
};

int main(){
    int n;
    cout<<"Enter the number of items:";
    cin>>n;
    vector<Item>items;
    for(int i=0;i<n;++i){
        int key,frequency;
        cout<<"Enter key and Frequency for Item"<<i+1<<":";
        cin>>key>>frequency;
        items.emplace_back(key,frequency);
    }
    OptimalBST ob(items);
    ob.printOptimalCost();
    ob.printOptimalStructure();
    return 0;
    }
