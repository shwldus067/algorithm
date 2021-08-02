#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, M, p[32000];
queue<int> Q;
vector<int> adj[32000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		p[b-1]++;
	}
	for(int i=0;i<N;++i){
		if(p[i]==0){
			Q.push(i);
		}
	}
	while(Q.size()){
		int cur=Q.front();
		cout<<cur+1<<" ";
		Q.pop();
		for(int v:adj[cur]){
			p[v]--;
			if(p[v]==0){
				Q.push(v);
			}
		}
	}
	return 0;
}
