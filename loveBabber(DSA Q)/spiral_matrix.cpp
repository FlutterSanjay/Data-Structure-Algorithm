#include<iostream>
#include<vector>
using namespace std;

void spiralPrint(vector<vector<int>>ans){
int startingRow=0;
int endingRow=ans.size()-1;
int startingCol=0;
int endingCol=ans[0].size()-1;
int total_element=ans.size()*ans[0].size();
int count=0;
while(count<total_element){

for(int i=startingCol;i<=endingCol && count<total_element;i++){
    cout<<ans[startingRow][i]<<" ";
    count++;
}
startingRow++;

for(int i=startingRow;i<=endingRow && count<total_element;i++){
    cout<<ans[i][endingCol]<<" ";
    count++;
}
endingCol--;

for(int i=endingCol;i>=startingCol && count<total_element;i--){
    cout<<ans[endingRow][i]<<" ";
    count++;
}
endingRow--;
for(int i= endingRow;i>=startingRow && count<total_element;i--){
    cout<<ans[i][startingCol]<<" ";
    count++;
}
startingCol++;
}
}

int main(){
    vector<vector<int>>ans{{1,2,3},{4,5,6},{7,8,9}};
    spiralPrint(ans);
    return 0;
}