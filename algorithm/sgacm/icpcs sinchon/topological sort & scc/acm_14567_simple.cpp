#include<iostream>
#include<vector>
using namespace std;
int N, M, d[1001];
vector<int> adj[1001];
int sol(int i){
	int &ret=d[i];
	if(ret)	return ret;
	for(int n:adj[i]){
		ret=max(ret, sol(n));
	}
	return ++ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[b].push_back(a);
	}
	for(int i=1;i<=N;++i){
		cout<<sol(i)<<" ";
	}
	return 0;
}
