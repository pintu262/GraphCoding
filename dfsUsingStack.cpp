#include <bits/stdc++.h>
using namespace std;
void DFSUtils(vector<vector<int>> &g,int i,bool visited[],int n){
    visited[i]=true;
    cout<<i<<" ";
    for(auto it=g[i].begin();it!=g[i].end();it++){
        if(!visited[(*it)]){
            DFSUtils(g,(*it),visited,n);
        }
    }
}
void DFSUtilStack(vector<vector<int>> &g,int i,bool visited[],int n){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        int v = s.top();s.pop();
        if(!visited[v]){
            visited[v]=true;
            cout<<v<<" ";
            for(auto it=g[v].begin();it!=g[v].end();it++){
                if(!visited[(*it)]){
                    s.push(v);
                    s.push(*it);
                    break;
                }
            }
        }
    }
    
}
void dfs(vector<vector<int>> &g,int n){
    bool visited[n]={0};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFSUtilStack(g,i,visited,n);
            cout<<endl;
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> g;
    g.assign(n,vector<int>());
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    dfs(g,n);
}
/*
Input:
4 4
1 0
1 2
3 0
3 2
Output:
0 
1 2 
3 

*/