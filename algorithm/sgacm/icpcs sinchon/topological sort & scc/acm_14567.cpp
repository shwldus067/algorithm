#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, ans[1001], p[1001], cnt=1;
vector<int> adj[1001];
queue<int> Q;
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
	for(int i=0;i<=N;++i){
		if(p[i]==0){
			Q.push(i);
		}
	}
	while(int size=Q.size()){
		while(size--){
			int cur=Q.front();
			Q.pop();
			ans[cur]=cnt;
			for(int n:adj[cur]){
				p[n]--;
				if(p[n]==0){
					Q.push(n);
				}
			}
		}
		cnt++;
	}
	for(int i=1;i<=N;++i)	cout<<ans[i]<<" ";
	return 0;
}
