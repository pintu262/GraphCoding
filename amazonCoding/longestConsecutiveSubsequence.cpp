#include <bits/stdc++.h>
using namespace std;
pair<int,int> longestConsecutiveSubsequence(int arr[],int n){
    set<int> s(arr,arr+n);
    int longestConSS=1;
    int startIndex=0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1)==s.end()){
            int cur = arr[i]+1;
            int curConSS = 1;
            while(s.find(cur)!=s.end()){
                curConSS++;
                cur +=1;
            }
            if(curConSS>longestConSS){
                startIndex =arr[i];
                longestConSS = curConSS;
            }
        }
    }
    return make_pair(longestConSS,startIndex);
}
int main() {
    // Longest Consecutive subsequence in an array and what is the starting point
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int> lcs = longestConsecutiveSubsequence(arr,n);
    cout<<lcs.first<<endl;
    int val = lcs.second;
    for(int i=0;i<lcs.first;i++){
        cout<<val++<<" ";
    }cout<<endl;
}
/*
Input :
6
2 1 6 9 4 3
Output:
4
1 2 3 4 
*/