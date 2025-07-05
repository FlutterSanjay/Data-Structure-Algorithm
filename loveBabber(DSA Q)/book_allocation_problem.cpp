// Book Allocation Problem
#include<bits/stdc++.h>
using namespace std;
class BookAllocation{
    public:
    bool isPossible(vector<int>A,int N,int M,int sol){
        int studentCount=1;
        int pageSum=0;
        for(int i=0;i<N;i++){
            if(A[i]>sol) return false;
            if(pageSum+A[i]>sol){
                studentCount++;
                pageSum=A[i];
                if(studentCount>M) return false;
                
            }
            else{
                pageSum+=A[i];
            }
        }
        return true;
    }
    int findPage(vector<int>& A,int M){
        int N=A.size();
        if(M>N) return -1;
        int s=0;
        int e=accumulate(A.begin(),A.end(),0);
        int ans=-1;
        while(s<=e){
            int mid=(s+e)>>1;
            if(isPossible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> A={12,34,67,90};
    int M=2;
    BookAllocation b;
    int result=b.findPage(A,M);
    cout<<"Minimum no of Pages allocated to each student : "<<result;
    return 0;
}