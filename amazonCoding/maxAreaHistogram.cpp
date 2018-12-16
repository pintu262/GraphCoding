#include <bits/stdc++.h>
using namespace std;
int largestAreaInHistogram(int arr[],int n){
    stack<int> s;// store the index of the element push into it
    int maxArea=0;
    int curArea=0;
    s.push(0);
    int i=0;
    for(i=1;i<n;i++){
        if(arr[s.top()]<=arr[i]){
            s.push(i);
        }else{
            while(!s.empty() && arr[s.top()]>arr[i]){
                int val = arr[s.top()];
                s.pop();
                if(!s.empty()){
                    curArea = (i- s.top() -1)*val;
                }else{
                    curArea = i*val;
                }
                if(curArea>maxArea){
                    maxArea = curArea;
                }
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int val = arr[s.top()];
        s.pop();
        if(!s.empty()){
            curArea = (i-s.top()-1)*val;
        }else{
            curArea = i*val;
        }
        if(curArea>maxArea){
            maxArea = curArea;
        }
    }
    return maxArea;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<largestAreaInHistogram(arr,n)<<endl;
    }
    
    return 0;
}
/*
Input:
3
8
1 2 3 4 5 3 3 2
3
1 2 4
5
2 1 2 3 1

Output:
15
4
5

*/