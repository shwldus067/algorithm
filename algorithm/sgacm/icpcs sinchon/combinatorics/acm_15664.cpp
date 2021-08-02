#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
int arr[9];
bool chk[9];
void sol(int n, int k, string s){
	if(n==M){
		cout<<s<<"\n";
		return;
	}
	for(int i=k;i<=N;++i){
		if(arr[i-1]==arr[i] && !chk[i-1])	continue;
		if(chk[i])	continue;
		chk[i]=1;
		sol(n+1, i+1, s+to_string(arr[i])+" ");
		chk[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
	}
	sort(arr+1, arr+N+1);
	sol(0, 1, "");
	return 0;
}
