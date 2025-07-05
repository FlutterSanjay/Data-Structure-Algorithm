// sort the Element
#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack,int num){
    // base case
    // check the stack is empty or not OR if stack in not empty and stack top value is less than num
    // then push the Element and return it;
    if(stack.empty()||(!stack.empty() && stack.top()<num)){ 
        stack.push(num);
        return ;
    }

    int n=stack.top(); // n store the stack top Element
    stack.pop(); // remove the top Element of stack

    //recursive call

    sortedInsert(stack,num);
    stack.push(n); // insert the Element in the stack
}

void sortStack(stack<int> & stack){
    // base case

    if(stack.empty()){  // if the stack is empty the return
        return ;
    }
    int num=stack.top(); //storesd the stack top element in num
    stack.pop();         //Remove the top Eleent from stack

    sortStack(stack);        //calling the sortStack function
    sortedInsert(stack,num);  // calling the SortedInsert function
}
 // output section that give the expected result
void output(stack<int> st,int size){
    for(int i=0;i<size;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    stack<int> st;  // declaring the stack
    int size,data;  // stack and data declaration
    // taking the size of Stack
    cout<<"Enter the Size od Stack : ";
    cin>>size;

// inserting the Element in stack
    for(int i=0;i<size;i++){
        cout<<"Enter your NO :" ;
        cin>>data;
        st.push(data);
    }
    sortStack(st);  // calling the SortStack function
    output(st,size);  // calling the outut function
    return 0;
}