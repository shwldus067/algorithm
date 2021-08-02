#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int x, c, d;
	bool operator<(const node &a)const{
		return d>a.d;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, M, K, u, v, c, d;
	cin>>T;
	while(T--){
		cin>>N>>M>>K;
		vector<node> adj[N+1];
		vector<vector<int> > dp(101, vector<int>(10001, (int)1e9));
		while(K--){
			cin>>u>>v>>c>>d;
			adj[u].push_back({v, c, d});
		}
		priority_queue<node> pq;
		pq.push({1, 0, 0});
		dp[1][0]=0;
		int fail=1;
		while(pq.size()){
			node cur=pq.top();
			pq.pop();
			if(cur.x==N){
				cout<<cur.d<<"\n";
				fail=0;
				break;
			}
			if(dp[cur.x][cur.c]<cur.d)	continue;
			for(node &nxt:adj[cur.x]){
				if(cur.c+nxt.c>M)	continue;
				if(dp[nxt.x][cur.c+nxt.c]>cur.d+nxt.d){
					dp[nxt.x][cur.c+nxt.c]=cur.d+nxt.d;
					pq.push({nxt.x, cur.c+nxt.c, cur.d+nxt.d});
				}
			}
		}
		if(fail)	cout<<"Poor KCM\n";
	}
	return 0;
}
