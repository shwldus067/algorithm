#include<iostream>
#include<vector>
using namespace std;
int N, M, C, S[100001], ind[100001];
int Q[100001], idx;
vector<pair<int, int> > adj[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>C;
	for(int i=1;i<=N;++i)	cin>>S[i];
	while(C--){
		int a, b, x;
		cin>>a>>b>>x;
		adj[a].push_back({b, x});
		++ind[b];
	}
	for(int i=1;i<=N;++i){
		if(ind[i]==0){
			Q[idx++]=i;
		}
	}
	while(idx){
		int cur=Q[--idx];
		for(pair<int, int> &tmp:adj[cur]){
			int nxt=tmp.first;
			S[nxt]=max(S[nxt], S[cur]+tmp.second);
			if(--ind[nxt]==0){
				Q[idx++]=nxt;
			}
		}
	}
	for(int i=1;i<=N;++i){
		cout<<S[i]<<"\n";
	}
	return 0;
}
