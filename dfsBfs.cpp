#include <bits/stdc++.h>
using namespace std;
void dfsUtil(vector<vector<int>> &g,int u,vector<bool> &visited){
    visited[u]=true;
    cout<<u<<"->";
    for(auto it=g[u].begin();it!=g[u].end();it++){
        if(visited[*it]==false){
            dfsUtil(g,*it,visited);
        }
    }
}
void dfs(vector<vector<int>> &g,int n){
    vector<bool> visited;visited.assign(n,false);
    for(int u=0;u<n;u++){
        if(visited[u]==false){
            dfsUtil(g,u,visited);cout<<endl;
        }
    }
    cout<<endl;
}
void dfsStackUtil(vector<vector<int>> &g,int u,vector<bool> &visited){
    stack<int> s;
    s.push(u);
    while(!s.empty()){
        int v = s.top();s.pop();
        if(visited[v]==false){
            cout<<v<<"->";
            visited[v]=true;
            for(auto it=g[v].rbegin();it!=g[v].rend();it++){
                if(!visited[*it]){
                    s.push(*it);
                }
            }
        }
    }
}
void dfsStack(vector<vector<int>> &g,int n){
    vector<bool> visited;visited.assign(n,false);
    for(int u=0;u<n;u++){
        if(visited[u]==false){
            dfsStackUtil(g,u,visited);cout<<endl;
        }
    }
    cout<<endl;
}
void bfsUtils(vector<vector<int>> &g,vector<bool> &visited,int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v=q.front();q.pop();
        if(visited[v]==false){
            visited[v]=true;
            cout<<v<<"->";
            for(auto it=g[v].begin();it!=g[v].end();it++){
                if(visited[*it]==false){
                    q.push(*it);
                }
            }
        }
    }
}
void bfs(vector<vector<int>> &g,int n){
    vector<bool> visited;visited.assign(n,false);
    for(int u=0;u<n;u++){
        if(visited[u]==false){
            bfsUtils(g,visited,u);
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
    for(int i=0;i<(2*e)-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    dfs(g,n);cout<<endl;
    dfsStack(g,n);cout<<endl;
    bfs(g,n);
}
