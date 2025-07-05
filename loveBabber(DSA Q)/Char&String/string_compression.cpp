// String Compression
#include<bits/stdc++.h>
using namespace std;
int stringCompression(vector<char>&s){
    int index = 0;
    char p = s[0];
    int count = 1;

    for (int i = 1; i < s.size();i++){
        if(s[i]==p){
            count++;
        }else{
            s[index++] = p;
            if(count>1){
                int start = index;
                while (count){
                    s[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            p = s[i];
            count = 1;
        }
    }
     s[index++] = p;
            if(count>1){
                int start = index;
                while (count){
                    s[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
           
     
            return index;
}

int main(){
    vector<char> s = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b'};
    int result = stringCompression(s);
    cout << result << endl;

    return 0;
}