#include <bits/stdc++.h>
using namespace std;
// Miniumum number of class required to accumadate all the lectures 
struct ClassTime{
    bool start;
    int times;
};
bool mycomparator(ClassTime l1,ClassTime l2){
    if(l1.times==l2.times){
        if(l1.start!=l2.start){
            if(!l1.start){
                return true;
            }else{
                return false;
            }
        }
    }
    return l1.times<l2.times;
}
int minimumClassRequired(ClassTime arr[],int n){
    sort(arr,arr+n,mycomparator);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].times<<"("<<arr[i].start<<")\t";
    // }cout<<endl;
    int classes =0;
    int maximum =0;
    for(int i=0;i<(n);i++){
        if(arr[i].start==true){
            classes++;
        }else{
            classes--;
        }
        if(classes > maximum){
            maximum = classes;
        }
    }
    return maximum;
}
int main() {
    int n;// number of lectures
    cin>>n;
    ClassTime arr[2*n];
    for(int i=0;i<2*n;i++){
        int s;
        cin>>s;
        if(i%2==0){
            arr[i].times=s;
            arr[i].start=true;
        }else{
            arr[i].times=s;
            arr[i].start=false;
        }
        
    }
    
    cout<<minimumClassRequired(arr,2*n)<<endl;
}
/*
Input: 
7
0 10
0 1
2 3
4 9
0 5
6 7
8 9
Output:
3
*/