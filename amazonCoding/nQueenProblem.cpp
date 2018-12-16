#include <bits/stdc++.h>
using namespace std;
bool isThreaten(int i,int queen,vector<pair<int,int>> &queenPos){
    for(auto it=queenPos.begin();it!=queenPos.end();it++){
        if((*it).first == i || abs((*it).first-i)==abs((*it).second - queen)){
            return true;
        }
    }
    return false;
}
bool placeQueen(int i,int n,int queen,vector<pair<int,int>> &queenPos){
    queenPos.push_back(make_pair(i,queen));
    if(queen>=n-1){
        return true;
    }
    for(int j=0;j<n;j++){
        if(!isThreaten(j,queen+1,queenPos)){
            if(placeQueen(j,n,queen+1,queenPos)){
                return true;
            }
        }
    }
   queenPos.pop_back();
   return false;
}
bool nQueenProblem(int n,vector<pair<int,int>> &queenPos){
   int queen=0;
   for(int i=0;i<n;i++){
       if(placeQueen(i,n,queen,queenPos)){
           return true;
       }
   }
   return false;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> queenPos;
    if(nQueenProblem(n,queenPos)){
        for(auto it=queenPos.begin();it!=queenPos.end();it++){
            cout<<"("<<(*it).first<<","<<(*it).second<<")\t";
        }
        cout<<endl;
    }else{
        cout<<"Not Possible to place the queen"<<endl;
    }
    return 0;
}