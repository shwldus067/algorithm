#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, p[32001];
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> adj[32001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		p[b]++;
	}
	for(int i=1;i<=N;++i){
		if(p[i]==0)	pq.push(i);
	}
	while(pq.size()){
		int cur=pq.top();
		pq.pop();
		cout<<cur<<" ";
		for(int n:adj[cur]){
			p[n]--;
			if(p[n]==0)	pq.push(n);
		}
	}
	return 0;
}
