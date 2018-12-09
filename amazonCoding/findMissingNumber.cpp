#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n-1];// Number is in range 1 to n;
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}
	int sc = arr[0];// xor of the current array
	int sn = n^(n-1);
	for(int i=1;i<n-1;i++){
		sc = sc^arr[i];
		sn = sn^i;
	}
	cout<<"Missing Number is: "<<(sc^sn)<<endl;
}
/*
5
1 3 5 4
*/