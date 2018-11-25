#include <bits/stdc++.h>
using namespace std;
void getInDegree(vector<vector<int>> &g,int n,vector<int> &inDegree){//O(V+E)
    for(int u=0;u<n;u++){
        for(auto it=g[u].begin();it!=g[u].end();it++){
            inDegree[*it]++;
        }
    }
}
void topologicalSort(vector<vector<int>> &g,int n){//O(v+e)
    vector<int> inDegree;
    inDegree.assign(n,0);
    getInDegree(g,n,inDegree);//O(V+E)
    queue<int> q;//collect all node with indegree 0;
    for(int u=0;u<n;u++){
        if(inDegree[u]==0){
            q.push(u);
            inDegree[u]=-1;
        }
    }
    while(!q.empty()){
        int v =q.front();q.pop();
        cout<<v<<"->";
        for(auto it=g[v].begin();it!=g[v].end();it++){
            inDegree[*it]--;
            if(inDegree[*it]==0){
                q.push(*it);
                inDegree[*it]=-1;
            }
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> g;//Not having weight
    g.assign(n,vector<int>());
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    for(int i=0;i<(e)-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    topologicalSort(g,n);
}
