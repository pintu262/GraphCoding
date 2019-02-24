#include <bits/stdc++.h>
#include<cstring>
#include<string.h>
using namespace std;
void getValueFromString(string str,vector<int> &v){
    int len = str.length();
    int prev =0,cur=0,num1;
    string num;
    for(int i=1;i<len;i++){
        if(str[i]==','){
            cur = i;
            num = str.substr(prev,cur-prev);
            // cout<<num<<endl;
            num1 =stoi(num);
            v.push_back(num1);
            prev = i+1;
        }
    }
    num = str.substr(prev,len-prev);
    num1 =stoi(num);
    v.push_back(num1);
    // cout<<num<<endl;
    // cout<<endl;
    // for(auto it = v.begin();it!=v.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
}
void printHistogram(vector<int> &v,int bucket){
    map<int,int> m;
    // for(auto it=v.begin();it!=v.end();it++){
    //     cout<<(*it)<<endl;
    // }
    int maxVal = 0;
    for(auto it=v.begin();it!=v.end();it++){
        
        int x = (*it)-1;
        int index = x/bucket;
        // cout<<index<<endl;
        if(m.find(index)!=m.end()){
            m[index]++;
        }else{
            m[index]=1;
            // m.insert(make_pair(index,1));
            if(index>maxVal){
                maxVal = index;
            }
        }
    }
    
    for(int i=0;i<=maxVal;i++){
        cout<<(i*bucket)+1<<"-"<<(i+1)*bucket<<" = ";
        if(m.find(i)!=m.end()){
            cout<<m[i]<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    
}
int main() {
    string str;
    getline(cin, str);
    // cin.ignore();
    int bucket;
    cin>>bucket;
    vector<int> v;
    // cout<<str<<endl;
    getValueFromString(str,v);
    
    printHistogram(v,bucket);
    return 0;
}
