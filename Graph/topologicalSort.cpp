#include <bits/stdc++.h>
using namespace std;
void topologicalSort(vector<vector<int>> &g,int v,int e){
    int indegree[v]={0};
    for(int i=0;i<v;i++){
        for(auto it=g[i].begin();it!=g[i].end();it++){
            indegree[(*it)]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<"->";
        for(auto it=g[u].begin();it!=g[u].end();it++){
            indegree[(*it)]--;
            if(indegree[(*it)]==0){
                q.push((*it));
            }
        }
    }
    cout<<endl;
}
int main() {
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g;
    g.assign(v,vector<int>());
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }
    
    topologicalSort(g,v,e);
}
