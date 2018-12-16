#include <bits/stdc++.h>
using namespace std;
vector<int> findRepeatedElement(int arr1[],int n1,int arr2[],int n2,int arr3[],int n3){
    int i=0,j=0,k=0;
    vector<int> v;
    while(i<n1 && j<n2 && k<n3){
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
            v.push_back(arr1[i]);
            i++;j++;k++;
        }else{
            if(arr1[i]<=arr2[j] && arr1[i]<=arr3[k]){
                i++;
            }else if(arr2[j]<=arr1[i] && arr2[j]<=arr3[k]){
                j++;
            }else{
                k++;
            }
        }
    }
    return v;
}
int main() {
    //Given 3 sorted arrays find the common element in the array in O(max(n1,n2,n3))
    int n1,n2,n3;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cin>>n3;
    int arr3[n3];
    for(int i=0;i<n3;i++){
        cin>>arr3[i];
    }
    vector<int> repetedElement = findRepeatedElement(arr1,n1,arr2,n2,arr3,n3);
    if(!repetedElement.empty()){
        for(auto it=repetedElement.begin();it!=repetedElement.end();it++){
            cout<<(*it)<<" ";
        }
    }else{
        cout<<"No element Found";
    }
    cout<<endl;
    return 0;
}
/*
Input:
6
2 6 9 11 13 17
6
3 6 7 10 13 18
7
4 5 6 9 11 13 19

Output:
6 13 
*/