#include <bits/stdc++.h>
using namespace std;
/*
Rain Water Storing: There is a given array of length n. Each element show the height of wall(Stairs).
Example:
4 3 2 1
Output: 0
Example:
4 3 1 5
Output: 4
*/
int getWaterStored(int arr[],int n){
    int lMax[n];
    int rMax[n];
    int minMax[n];
    lMax[0]=arr[0];
    rMax[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        lMax[i] = max(arr[i],lMax[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rMax[i] = max(arr[i],rMax[i+1]);
    }
    for(int i=0;i<n;i++){
        minMax[i] = min(lMax[i],rMax[i]);
    }
    int waterStored = 0;
    for(int i=0;i<n;i++){
        waterStored += minMax[i]-arr[i];
    }
    return waterStored;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<getWaterStored(arr,n)<<endl;
    }
}
