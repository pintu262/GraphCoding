#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int> leftpq;//left As it is max heap
    priority_queue<int,vector<int>,greater<int>> rightpq;//right as it It is minHeap
    int x,y;
    cin>>x;
    cout<<x<<endl;
    if(n>=2){
	    cin>>y;
	    cout<<((x+y)/2)<<endl;
	    if(x>y){
	        rightpq.push(x);
	        leftpq.push(y);
	    }else{
	        rightpq.push(y);
	        leftpq.push(x);
	    }
    }
    for(int i=2;i<n;i++){
        cin>>x;
        if(leftpq.size()==rightpq.size()){
            if(x<=rightpq.top()){
                leftpq.push(x);
            }else{
                leftpq.push(rightpq.top());rightpq.pop();
                rightpq.push(x);
            }
            cout<<leftpq.top()<<endl;
        }else if(leftpq.size()==rightpq.size()+1){
            if(x>=leftpq.top()){
                rightpq.push(x);
            }else{
                rightpq.push(leftpq.top());leftpq.pop();
                leftpq.push(x);
            }
            cout<<(leftpq.top()+rightpq.top())/2<<endl;
        }else{
            if(x<=rightpq.top()){
                leftpq.push(x);
            }else{
                leftpq.push(rightpq.top());rightpq.pop();
                rightpq.push(x);
            }
            cout<<(leftpq.top()+rightpq.top())/2<<endl;
        }
    }
	return 0;
}
/*
Input:
5
5 4 3 2 1
Output:
5 4 4 3 3
*/
