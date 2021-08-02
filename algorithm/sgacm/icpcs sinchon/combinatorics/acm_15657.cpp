#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
int arr[8];
void sol(int n, int k, string s){
	if(n==M){
		cout<<s<<"\n";
		return;
	}
	for(int i=k;i<N;++i){
		sol(n+1, i, s+to_string(arr[i])+" ");
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr, arr+N);
	sol(0, 0, "");
	return 0;
}
