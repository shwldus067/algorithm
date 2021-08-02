#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > pip;
char dp[15][1<<15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, ans=0;
	char price[15][16];
	queue<pip> Q;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>price[i];
	Q.push({0, {0, 1}});
	for(int i=0;i<N;++i)for(int j=0;j<(1<<N);++j)	dp[i][j]=10;
	dp[0][1]=0;
	while(Q.size()){
		int cur=Q.front().first, cnt=0;
		int cost=Q.front().second.first;
		int state=Q.front().second.second;
		Q.pop();
		if(dp[cur][state]<cost)	continue;
		dp[cur][state]=-1;
		for(int i=0;i<N;++i){
			if(state&(1<<i)){++cnt;continue;}
			if(price[cur][i]-'0'<cost)	continue;
			int t=state|(1<<i);
			if(dp[i][t]<price[cur][i]-'0')	continue;
			Q.push({i, {price[cur][i]-'0', t}});
			dp[i][t]=price[cur][i]-'0';
		}
		ans=max(ans, cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
