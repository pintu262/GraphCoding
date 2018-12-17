#include <bits/stdc++.h>
using namespace std;
void moveAllZerosToEndInPlace(int arr[],int n){
    int i=0,j=n-1;
    while(i<j && i<n && j>=0){
        while(arr[i]!=0 && i<n)i++;
        while(arr[j]==0 && j>=0)j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return;
}
void moveAllZerosToEndWithoutChangingPosition(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i+1;
            while(j<n && arr[j]==0)j++;
            if(j<n){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],arr2[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr2[i]=arr[i];
        }
        moveAllZerosToEndInPlace(arr,n);
        moveAllZerosToEndWithoutChangingPosition(arr2,n);cout<<endl;
    }
}
/*
Input:
3
6
1 0 2 0 3 0
6
1 2 1 3 4 -1
6
1 2 3 4 5 6

Output:
1 3 2 0 0 0 
1 2 3 0 0 0 

1 2 1 3 4 -1 
1 2 1 3 4 -1 

1 2 3 4 5 6 
1 2 3 4 5 6 
*/