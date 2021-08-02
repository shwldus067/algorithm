#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const long long mod=1000000007;
int N, A, B, W;
vector<pair<int, int> > adj[100001];
long long res;
long long sol(int s, int p){
	long long tmp, cur=1;
	for(int i=adj[s].size()-1;i>=0;--i){
		int next=adj[s][i].first;
		if(p==next)	continue;
		int weight=adj[s][i].second;
		tmp=sol(next, s)*weight%mod;
		res=(res+tmp*cur)%mod;
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
