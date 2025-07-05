/* Redundant Bracket:-
   A set of parenthesis is redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. 

example:-

Input: str = “((a+b))”
Output: YES
Explanation: ((a+b)) can reduced to (a+b), this Redundant
*/

#include<iostream> // used for input and output purpose
#include<stack> // used for using or implementing stack
#include<string> // used for using string 
#include<stdbool.h> // used for boolean character
using namespace std;

// This function check the string is redundant or not and return flase or true to calling place
bool find(string &s){
    stack<int> st;   // declaring stack
    for(int i=0;i<s.length();i++){
        char ch=s[i];   // store the each character in ch

        if(ch=='('|| ch=='+'|| ch=='-'|| ch=='*' || ch=='/'){   // compare ch with this element
            st.push(ch);
        }
        else{
            if(ch==')'){ // other wise check ending curly bracket
                bool finds=true;     // assign true if ch found
                while(st.top()!='('){
                    char top=st.top();  // assign the top element of stack in top

                    if(top=='+' || top=='-' || top=='*' || top=='/'){ // comparing the top with the given character 
                        finds=false;  // assign the false
                    }
                    st.pop();  // remove the last the element from stack
                }
                if(finds==true)  // check the given find variable matched with true or not
                    return true; // match then send true

                    st.pop();   // remove the last element from the stack
                }
            }
        }
        return false; // otherwise return false
}


    int main(){
        string str="((a+b))"; // given string
       bool result= find(str);
       cout<<result;          // if string is redundant then print 1
                              // other wise print 0;
       return 0;     
        
    }
