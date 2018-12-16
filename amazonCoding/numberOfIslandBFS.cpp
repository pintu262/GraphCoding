#include <bits/stdc++.h>
using namespace std;
const int R=100,C=100;
int movi[]={-1,-1,-1,0,0,1,1,1};
int movj[]={-1,0,1,-1,1,-1,0,1};
bool isSafe(int M[R][C],int r,int c,int i,int j){
    if(i<0 ||i>=r||j<0||j>=c){
        return false;
    }else if(M[i][j]==0||M[i][j]==-1||M[i][j]==-2){
        return false;
    }else{
        return true;
    }
}
void BFS(int M[R][C],int r,int c,int i,int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    M[i][j]=-1;
    while(!q.empty()){
        pair<int,int> v = q.front();
        q.pop();
        M[v.first][v.second]=-2;
        for(int k=0;k<8;k++){
            int newi=movi[k]+v.first;
            int newj=movj[k]+v.second;
            if(isSafe(M,r,c,newi,newj)){
                M[newi][newj]=-1;
                q.push(make_pair(newi,newj));
            }
        }
    }
}
int main() {
    int r,c;
    cin>>r>>c;
    int M[R][C];
    int numberOfIsland=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>M[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(M[i][j]==1){
                BFS(M,r,c,i,j);
                numberOfIsland++;
            }
        }
    }
    cout<<"Number Of Islands = "<<numberOfIsland<<endl;
}

/*
Input:
5 6
1 0 0 0 0 1
1 1 0 0 1 1
0 1 0 0 0 0
0 0 0 1 0 0
1 0 0 0 1 1

Output:
Number Of Islands = 4
*/