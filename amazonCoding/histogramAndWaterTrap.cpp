#include <bits/stdc++.h>
using namespace std;
int largestAreaUnderHistogram(int arr[],int n){
    int curArea =0,maxArea =0;
    stack<int> s;
    s.push(0);
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>=arr[s.top()]){
            s.push(i);
        }else{
            while(!s.empty() && arr[i]<arr[s.top()]){
                int v = arr[s.top()];s.pop();
                if(!s.empty()){
                    curArea = (i-s.top()-1)*v;
                }else{
                    curArea = i*v;
                }
                if(curArea > maxArea){
                    maxArea = curArea;
                }
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int v = arr[s.top()];s.pop();
        if(!s.empty()){
            curArea = (i-s.top()-1)*v;
        }else{
            curArea = i*v;
        }
        if(curArea > maxArea){
            maxArea = curArea;
        }
    }
    return maxArea;
}
int maximumWaterTraps(int arr[],int n){
    int l[n],r[n];
    l[0]=arr[0];
    r[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        l[i] = max(l[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        r[i] =max(r[i+1],arr[i]);
    }
    int maxWaterTrap=0;
    for(int i=0;i<n;i++){
        if(l[i]==r[i]){
            continue;
        }else{
            maxWaterTrap += min(l[i],r[i]);
        }
    }
    return maxWaterTrap;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Largest Area Under Histogram = "<<largestAreaUnderHistogram(arr,n)<<endl;
    cout<<"Maximum Water Trap Under the walls = "<<maximumWaterTraps(arr,n)<<endl;
    
}
/*
    Input:
    6
    2 5 10 3 9 1
    Output:
    Largest Area Under Histogram = 12
    Maximum Water Trap Under the walls = 26
*/