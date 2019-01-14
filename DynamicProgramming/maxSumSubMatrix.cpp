#include <bits/stdc++.h>
using namespace std;
int kadanesAlgo(int arr[],int n,int &curl,int &curr){
    int cl=0,cr=0;
    curl=0,curr=0;
    int max = arr[0];
    int maxSoFar = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i]+max){
            cl=i;
            cr=i;
            max = arr[i];
        }else{
            cr = i;
            max = arr[i]+max;
        }
        if(max>maxSoFar){
            curl=cl;
            curr=cr;
            maxSoFar = max;
        }
    }
    return maxSoFar;
}
int maxSumSubMatrix(int **M,int row,int col,int &l,int &r,int &u,int &d){
    int curl,curr,curu,curd;
    int max,maxSoFar=INT_MIN;
    int uptr=0,dptr=0;
    for(uptr;uptr<row;uptr++){
        int arr[col];
        for(int i=0;i<col;i++){
            arr[i]=M[uptr][i];
        }
        max = kadanesAlgo(arr,col,curl,curr);
        if(max>maxSoFar){
            maxSoFar = max;
            l=curl;
            r=curr;
            u=uptr;
            d=dptr;
        }
        
        for(dptr=uptr+1;dptr<row;dptr++){
            for(int i=0;i<col;i++){
                arr[i]+=M[dptr][i];
            }
            max = kadanesAlgo(arr,col,curl,curr);
            if(max>maxSoFar){
                maxSoFar = max;
                l=curl;
                r=curr;
                u=uptr;
                d=dptr;
            }
        }
    }
    return maxSoFar;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int row,col;
        cin>>row>>col;
        int **M;
        M = new int*[row];
        for(int i=0;i<row;i++){
            M[i] = new int[col];
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>M[i][j];
            }
        }
        
        int l,r,u,d;
        int maxSum = maxSumSubMatrix(M,row,col,l,r,u,d);
        cout<<"MaxSum = "<<maxSum<<endl;
        
        for(int i=u;i<=d;i++){
            for(int j=l;j<=r;j++){
                cout<<setw(4)<<M[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
}

/*
Input:
2
5 4
3 -1 6 12
-6 8 -12 12
18 1 -10 12
-5 0 10 20
11 11 -1 2
4 5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3

Output:
MaxSum = 91
   3   -1    6   12 
  -6    8  -12   12 
  18    1  -10   12 
  -5    0   10   20 
  11   11   -1    2 

MaxSum = 18
   6    3    4 
  -2   -1    4 
   3    1    0 
*/