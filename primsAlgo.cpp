#include <bits/stdc++.h>
using namespace std;
struct mycomp{
    using is_transparent = int;
    bool operator()(const pair<int,pair<int,int>> &p1,const pair<int,pair<int,int>> &p2)const{//sort according to weight
        return p1.second.second<p2.second.second;
    }
    bool operator()(const pair<int,pair<int,int>> &p1,int u)const{//find in the set if u is present
        return p1.second.first<u;
    }
    bool operator()(int u,const pair<int,pair<int,int>> &p1)const{
        return u<p1.second.first;
    }
};
bool containCycle(vector<vector<pair<int,int>>> &st,int u,int v,int w,vector<bool> &visited){
    for(auto it=st[v].begin();it!=st[v].end();it++){
        int a,b;
        int adjNode = (*it).first;
        if(visited[adjNode]==true && adjNode !=u){
            return true;
        }
    }
    return false;
}
void spanningTree(vector<vector<pair<int,int>>> &g,vector<vector<pair<int,int>>> &st,int a,int n){
    vector<bool> visited;visited.assign(n,false);visited[a]=true;
    set<pair<int,pair<int,int>> ,mycomp> s;// <u,<v,w>>
    for(auto graphItr=g[a].begin();graphItr!=g[a].end();graphItr++){
        s.insert(make_pair(a,*graphItr));
    }
    while(!s.empty()){
        int u,v,w;
        u = (*(s.begin())).first;
        v = (*(s.begin())).second.first;
        w = (*(s.begin())).second.second;
        visited[v]=true;
        s.erase(s.begin());
        if(!containCycle(st,u,v,w,visited)){
            st[u].push_back(make_pair(v,w));
        }
        for(auto graphIt=g[v].begin();graphIt!=g[v].end();graphIt++){
            auto setIt=s.find((*graphIt).first);
            if( setIt !=s.end() && (*(setIt)).second.second> (*graphIt).second){
                s.erase(setIt);
                s.insert(make_pair(v,*graphIt));
            }else if(setIt==s.end()){
                s.insert(make_pair(v,*graphIt));
            }
        }
    }
}
void printSpanningTree(vector<vector<pair<int,int>>> &st,int n){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it=st[i].begin();it!=st[i].end();it++){
            cout<<"("<<(*it).first<<","<<(*it).second<<")->";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main() {
    int n,e;cin>>n>>e;

	vector<vector<pair<int,int>>> g;
	g.assign(n,vector<pair<int,int>>());
	
	vector<vector<pair<int,int>>> st;
	st.assign(n,vector<pair<int,int>>());
	
	int a,u,v,w;
	cin>>u>>v>>w;
	a=u;
	g[u].push_back(make_pair(v,w));
	for(int i=0;i<e-1;i++){
	    cin>>u>>v>>w;
	    g[u].push_back(make_pair(v,w));
	}
	
	spanningTree(g,st,a,n);
	
	printSpanningTree(st,n);
}
