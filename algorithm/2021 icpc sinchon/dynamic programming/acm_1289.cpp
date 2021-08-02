#include<iostream>
#include<vector>
using namespace std;
const long long mod=1000000007;
int N, A, B, W, res;
vector<pair<int, int> > adj[100001];
int sol(int s, int p){
	int tmp, cur=1;
	for(int i=0;i<adj[s].size();++i){
		int next=adj[s][i].first;
		if(p==next)	continue;
		tmp=(long long)sol(next, s)*adj[s][i].second%mod;
		res=(res+(long long)tmp*cur)%mod;
		cur=(cur+tmp)%mod;
	}
	return cur;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;++i){
		cin>>A>>B>>W;
		adj[A].push_back({B, W});
		adj[B].push_back({A, W});
	}
	sol(1, 0);
	cout<<res<<"\n";
	return 0;
}
