#include <bits/stdc++.h>
using namespace std;
// from youtube video: https://youtu.be/obWXjtg0L64

void bellmanFord(vector<vector<pair<int,int>>> &g,int n,int u){
    //n is the number of nodes so it will take atmost n-1 iteration to compute the sssp
    int pathTable[n][3];
    for(int i=0;i<n;i++){
        pathTable[i][0]=i;
        pathTable[i][1]=INT_MAX;
        pathTable[i][2]=-1;
    }
    pathTable[u][1]=0;
    bool flagToCheckMaxIteration=false;
    for(int i=0;i<n-1;i++){//n-1 iteration for the relaxing the table
        flagToCheckMaxIteration=false;
        for(int node=0;node<n;node++){
            for(auto it=g[node].begin();it!=g[node].end();it++){
                if(pathTable[node][1]==INT_MAX){
                    break;
                }
                int weight=pathTable[node][1]+(*it).second;
                if(pathTable[(*it).first][1]>weight){
                    pathTable[(*it).first][1]=weight;
                    pathTable[(*it).first][2]=node;
                    flagToCheckMaxIteration=true;
                }
            }
        }
        if(flagToCheckMaxIteration==false){
            cout<<"Iteration No : "<<i+1<<endl;
            break;
        }
    }
    //check for negative cycle
    for(int nodeCheck=0;nodeCheck<n;nodeCheck++){
        for(auto it=g[nodeCheck].begin();it!=g[nodeCheck].end();it++){
            if((pathTable[nodeCheck][1] != INT_MAX) &&(pathTable[(*it).first][1] != INT_MAX) && (pathTable[nodeCheck][1]+(*it).second < pathTable[(*it).first][1])){
                cout<<"Negative Cycle Found";
                return;
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
    bellmanFord(g,n,a);
}