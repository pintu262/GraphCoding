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
    vector<string> sol;
    string s;
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
        int vv=-1;
        if(!q.empty()){
            vv =q.front();q.pop();
        }
        for(auto it=g[v].begin();it!=g[v].end();it++){
            inDegree[*it]--;
            if(inDegree[*it]==0){
                q.push(*it);
                inDegree[*it]=-1;
            }
        }
        if(vv!=-1){
            s="2 "+to_string(v+1)+" "+to_string(vv+1);
            v=vv;
            for(auto it=g[v].begin();it!=g[v].end();it++){
                inDegree[*it]--;
                if(inDegree[*it]==0){
                    q.push(*it);
                    inDegree[*it]=-1;
                }
            }
        }else{
            s="1 "+to_string(v+1);
        }
        sol.push_back(s);
    }
    cout<<sol.size()<<endl;
    for(auto it=sol.begin();it!=sol.end();it++){
        cout<<*it<<endl;
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> g;
    g.assign(n,vector<int>());
    int u,v;
    cin>>u>>v;
    u=u-1;
    v=v-1;
    g[v].push_back(u);
    for(int i=0;i<(e)-1;i++){
        cin>>u>>v;
        u=u-1;v=v-1;
        g[v].push_back(u);
    }
    topologicalSort(g,n);
    // cout<<endl;
}
