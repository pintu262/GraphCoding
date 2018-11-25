#include <bits/stdc++.h>
using namespace std;
struct mycomp{
  using is_transparent = int;
  bool operator()(const pair<int,int> &p1,const pair<int,int> &p2)const{
      return p1.second<p2.second;
  }
  bool operator()(const pair<int,int> &p1,int u) const{
      return p1.first<u;
  }
  bool operator()(int u,const pair<int,int> &p1)const{
      return u<p1.first;
  }
};
void dijkastraSSSP(vector<vector<pair<int,int>>> &g,int n,int u){
    int pathTable[n][3];
    for(int i=0;i<n;i++){
        pathTable[i][0]=i;
        pathTable[i][1]=INT_MAX;
        pathTable[i][2]=-1;
    }
    pathTable[u][1]=0;
    set<pair<int,int>,mycomp> s;// node and min cost to reach there
    s.insert(make_pair(u,0));
    
    while(!s.empty()){
        auto vNode=s.begin();
        int v,w;
        v=(*vNode).first;
        w=(*vNode).second;
        s.erase(vNode);
        for(auto it=g[v].begin();it!=g[v].end();it++){
            int weight=pathTable[v][1]+(*it).second;
            if(pathTable[(*it).first][1]>weight){
                pathTable[(*it).first][1]=weight;
                pathTable[(*it).first][2]=v;
                if(s.find((*it).first)!=s.end()){
                    s.erase(s.find((*it).first));
                }
                s.insert(make_pair((*it).first,weight));
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
    vector<vector<pair<int,int>>> g;//Adj list with weight
    g.assign(n,vector<pair<int,int>>());
    int u,v,w,a;
    cin>>u>>v>>w;
    a=u;
    g[u].push_back(make_pair(v,w));
    for(int i=0;i<(e)-1;i++){
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
    }
    dijkastraSSSP(g,n,a);
}
