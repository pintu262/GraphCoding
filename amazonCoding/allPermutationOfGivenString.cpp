#include <bits/stdc++.h>
using namespace std;
void printPermutation(string s,int l,int h,set<string> &_set){
    if(l==h){
        _set.insert(s);
        return;
    }
    for(int i=l;i<=h;i++){
        swap(s[l],s[i]);
        printPermutation(s,l+1,h,_set);
        swap(s[l],s[i]);
    }
}
int main() {
    string s;
    cin>>s;
    set<string> _set;
    printPermutation(s,0,s.length()-1,_set);
    for(auto it=_set.begin();it!=_set.end();it++){
        cout<<(*it)<<endl;
    }
}
/*
Input:
ABBC
Output:
ABBC
ABCB
ACBB
BABC
BACB
BBAC
BBCA
BCAB
BCBA
CABB
CBAB
CBBA
*/