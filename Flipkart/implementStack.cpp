#include <bits/stdc++.h>
using namespace std;
struct SStack{
    stack<int> _stack;
    stack<int> _min_stack;
};
void push(SStack &s,int data){
    s._stack.push(data);
    if(s._min_stack.empty()){
        s._min_stack.push(data);
    }else{
        if(data <= s._min_stack.top()){
            s._min_stack.push(data);
        }
    }
}
int pop(SStack &s){
    if(s._stack.empty()){
        cout<<"Already Empty"<<endl;
        return -1;
    }
    int data = s._stack.top();
    s._stack.pop();
    if(data ==s._min_stack.top()){
        s._min_stack.pop();
    }
    return data;
}
int getMin(SStack &s){
    if(s._min_stack.empty()){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return s._min_stack.top();
}
int main() {
    SStack s;
    int t;
    cin>>t;
    string operation;
    int data;
    while(t--){
        cin>>operation;
        if(operation.compare("push")==0){
            cin>>data;
            push(s,data);
        }else if(operation.compare("pop")==0){
            int data = pop(s);
            if(data !=-1){
                cout<<data<<endl;
            }
        }else if(operation.compare("min")==0){
            int min = getMin(s);
            if(min!=-1){
                cout<<min<<endl;
            }
        }
    }
}
/*
Input:
9
push 5
push 3
push 3
push 1
pop
min
push 2
pop
min
Output:
1
3
2
3
*/