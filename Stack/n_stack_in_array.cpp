// N Stack in Array (Bhut Zada Important Question Hai for Placement)
#include<bits/stdc++.h>
using namespace std;

class NStack{
    public:
        int *a;
        int *top;
        int *next;

        int size;
        int n;
        int freespot;
        NStack(int s,int n){
            this->size = s;
            this->n = n;
            freespot = 0;
            a = new int[s];
            top = new int[n];
            next = new int[s];

            // put top=-1;
            for (int i = 0; i < n;i++){
                top[i] = -1;
            }

            // for next
            for (int i = 0; i < s;i++){
                next[i] = i + 1;
            }
            next[size - 1] = -1;
        }

        // push operation
        bool push(int x,int m){
            if(freespot == -1){
                return false; // stack is Overflow
            }

            // find Index
            int index = freespot;
            
            // update the freespot
            freespot = next[index];

            //insert in array
            a[index] = x;

            //update next
            next[index] = top[m - 1];

            //update top
            top[m - 1] = index;
            return true;
        }

    //pop Operation
    int pop(int m){
        if(top[m-1]==-1){
            return -1; // stack underflow;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return a[index];
    }
};
int main(){
    NStack st(10, 3);
    st.push(1, 1);
    st.push(2, 1);
    st.push(3, 1);
    st.push(4, 1);

    st.push(10, 2);
    st.push(20, 2);
    st.push(30, 2);

    st.push(8, 3);
    st.push(16, 3);
    st.push(24, 3);

    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(3) << endl;

    return 0;
}