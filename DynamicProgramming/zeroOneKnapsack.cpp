#include <bits/stdc++.h>
using namespace std;
int zeroOneKnapsack(int weight[],int profit[],int n,int weightOfKnapsack){
    int T[n+1][weightOfKnapsack+1];
    for(int i=0;i<=n;i++){
        T[i][0]=0;
    }
    for(int j=0;j<=weightOfKnapsack;j++){
        T[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=weightOfKnapsack;j++){
            if(j<weight[i-1]){
                T[i][j]=T[i-1][j];
            }else{
                T[i][j] = max(T[i-1][j],T[i-1][j-weight[i-1]]+profit[i-1]);
            }
        }
    }
    return T[n][weightOfKnapsack];
}
int main() {
    int n,w;
    cin>>n>>w;
    int profit[n];
    int weight[n];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    cout<<zeroOneKnapsack(weight,profit,n,w)<<endl;
}
/*
Input:
4 7
5 1 4 3
7 1 5 4
Output:
9
*/