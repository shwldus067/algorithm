#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
int inp[8], arr[8], c;
void sol(int n, string s){
	if(n==M){
		cout<<s<<"\n";
		return;
	}
	for(int i=0;i<c;++i){
		sol(n+1, s+to_string(arr[i])+" ");
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>inp[i];
	}
	sort(inp, inp+N);
	int p=0;
	for(int i=0;i<N;++i){
		if(p!=inp[i])	arr[c++]=inp[i], p=inp[i];
	}
	sol(0, "");
	return 0;
}
