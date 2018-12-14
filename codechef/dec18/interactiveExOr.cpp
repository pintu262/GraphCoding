#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        int temp[n+2]={0};
        for(i=0;i<n;i++){
            cout<<"1 "<<(i%n)+1<<" "<<((i+1)%n +1)<<" "<<((i+2)%n +1)<<endl;
            cin>>arr[i];
        }
        for(i=0;i<n;i++){
            int x = arr[i]^arr[(i+1)%n];
            temp[i+2]=x;
        }
        temp[0]=temp[n];
        temp[1]=temp[n+1];
        cout<<2<<" ";
        for(i=0;i<n;i++){
            cout<<(arr[i]^temp[i])<<" ";
        }
        cout<<endl;
        cout.flush();
        int res;
        cin>>res;
        if(res==-1){
            return 0;
        }
    }
}
