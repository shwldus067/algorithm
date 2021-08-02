#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int x, c, d;
};
int dp[101][10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, M, K, u, v, c, d;
	vector<node> adj[101];
	cin>>T;
	while(T--){
		cin>>N>>M>>K;
		for(int i=1;i<=N;++i){
			adj[i].clear();
			for(int j=0;j<=M;++j)	dp[i][j]=1e9;
		}
		while(K--){
			cin>>u>>v>>c>>d;
			adj[u].push_back({v, c, d});
		}
		queue<node> Q;
		Q.push({1, 0, 0});
		dp[1][0]=0;
		while(Q.size()){
			node cur=Q.front();
			Q.pop();
			if(dp[cur.x][cur.c]<cur.d)	continue;
			dp[cur.x][cur.c]=cur.d;
			for(node &nxt:adj[cur.x]){
				int nc=cur.c+nxt.c;
				int nd=cur.d+nxt.d;
				if(nc>M)	continue;
				if(dp[nxt.x][nc]>nd){
					for(int i=nc;i<=M;++i){
						if(dp[nxt.x][i]>nd)	dp[nxt.x][i]=nd;
						else	break;
					}
					Q.push({nxt.x, nc, nd});
				}
			}
		}
		if(dp[N][M]==1e9)	cout<<"Poor KCM\n";
		else	cout<<dp[N][M]<<"\n";
	}
	return 0;
}
