#include <bits/stdc++.h>
using namespace std;
bool mycomparator(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
void mostFrequentElement(int arr[],int n,multimap<int,int> &mostFrequentElement){
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end()){
            m[arr[i]]++;
        }else{
            m[arr[i]]=1;
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        mostFrequentElement.insert(make_pair((*it).second,(*it).first));
    }
}
int main() {
    //K most frequent element
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multimap<int,int> elements ;
    mostFrequentElement(arr,n,elements);
    if(!elements.empty()){
        int i=0;
        for(auto it=elements.rbegin();it!=elements.rend() &&i<k ;it++,i++){
            cout<<"["<<(*it).second<<" ("<<(*it).first<<")]  ";
        }cout<<endl;
    }else{
        cout<<"No Element Found"<<endl;
    }
}
/*
Input:
9 3
1 2 1 6 2 1 6 7 6
Output:
[6 (3)]  [1 (3)]  [2 (2)]  
[element (frequency)]