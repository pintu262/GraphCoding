#include <bits/stdc++.h>
using namespace std;
bool cycle(int arr[],int n){
    int r=0,t=0;
    while((r!=-1 ||r<n)&& (t!=-1 ||t<n)){
        r = arr[r];
        if(r>=n || r==-1){
            return false;
        }
        r = arr[r];
        if(r>=n || r==-1){
            return false;
        }
        t = arr[t];
        if(t>=n || t==-1){
            return false;
        }
        if( (r==t) && (r!=-1) && (r<n)){
            return true;
        }
    }
    return false;
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
        if(cycle(arr,n)){
            cout<<"Found Cycle in Array"<<endl;
        }else{
            cout<<"Do not Found Cycle in Array"<<endl;
        }
    }
}
/*
Input:
2
6
1 2 1 3 4 -1
6
1 2 3 4 5 6

Output:
Found Cycle in Array
Do not Found Cycle in Array
*/