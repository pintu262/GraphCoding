#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=low;
    int l=low;
    int h=high;
    while(l<=h){
        while(arr[l]<=arr[pivot])l++;
        while(arr[h]>arr[pivot])h--;
        if(l<h){
            swap(arr[l],arr[h]);
        }
    }
    swap(arr[h],arr[pivot]);
   return h;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pos = partition(arr,low,high);
        quickSort(arr,low,pos-1);
        quickSort(arr,pos+1,high);
    }
}
void printSort(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n]=INT_MAX;
    quickSort(arr,0,n);
    printSort(arr,n);
}
