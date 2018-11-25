#include <bits/stdc++.h>
using namespace std;
void shortestPathUnweightedGraph(vector<vector<int>> &g,int n,int u){
    int pathTable[n][3];//similar to tradational table
    for(int i=0;i<n;i++){
        pathTable[i][0]=i;
        pathTable[i][1]=INT_MAX;
        pathTable[i][2]=-1;
    }
    pathTable[u][1]=0;
    
    queue<int> q;
    vector<bool> visited;
    visited.assign(n,false);
    q.push(u);
    while(!q.empty()){
        int v = q.front();q.pop();
        visited[v]=true;
        for(auto it=g[v].begin();it!=g[v].end();it++){
            if(visited[*it]==false){
                pathTable[*it][1]=pathTable[v][1]+1;
                pathTable[*it][2]=v;
                q.push(*it);
            }
        }
    }
    cout<<"V"<<" "<<"W"<<" "<<"Via"<<endl;
    for(int i=0;i<n;i++){
        cout<<pathTable[i][0]<<" "<<pathTable[i][1]<<" "<<pathTable[i][2]<<endl;
    }
    
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> g;//Not having weight
    g.assign(n,vector<int>());
    int u,v,a;
    cin>>u>>v;
    a=u;
    g[u].push_back(v);
    for(int i=0;i<(e)-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    // topologicalSort(g,n);
    cout<<endl;
    shortestPathUnweightedGraph(g,n,a);
}
