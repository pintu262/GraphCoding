#include <bits/stdc++.h>
using namespace std;
const int R=1000,C=1000;
//Given a grid of 1's and 0's where I need to find the maximum size of rectangle formed by the 1's
void stackOperation(stack<int> &s,int i,int &curArea,int &maxArea,int arr[],int n){
    int t;
    t=s.top();s.pop();
    if(!s.empty()){
        curArea = (i - s.top() -1)*arr[t];
    }else{
        curArea = (i)*(arr[t]);
    }
    if(curArea>maxArea){
        maxArea = curArea;
    }
}
int maxAreaUnderHistogram(int arr[],int n){
    stack<int> s;
    s.push(0);
    int curArea = 0;
    int maxArea = 0;
    int t;
    int i=0;
    for(i=1;i<n;i++){
        while(!s.empty() && arr[i]<arr[s.top()]){
          stackOperation(s,i,curArea,maxArea,arr,n);
        }
        s.push(i);
    }
    while(!s.empty()){
        stackOperation(s,i,curArea,maxArea,arr,n);
    }
    return maxArea;
}
int maxRectangle(int grid[R][C],int r,int c){
    int arr[c]={0};
    int maxArea = 0;
    int curArea = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[j] = (grid[i][j]==0)?0:(arr[j]+grid[i][j]);
        }
        curArea = maxAreaUnderHistogram(arr,c);
        if(curArea > maxArea){
            maxArea = curArea;
        }
    }
    return maxArea;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int grid[R][C];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
        cout<<maxRectangle(grid,r,c)<<endl;
    }
    
}
/*
Input:
2
4 4
0 1 1 0
1 1 1 0
1 1 1 1
1 1 0 0
5 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
1 1 1 1
Output:
6
8
*/