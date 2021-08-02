#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, M, K, arr[10][10], idx=1;
int dr[4]={-1, 1, 0, 0}, dc[4]={0, 0, -1, 1};
int ans[7][7], dp[64];
vector<pii> island[7];
struct vec{
	int r, c, d;
};
void fisland(int i, int j){
	queue<pii> Q;
	Q.push({i, j});
	arr[i][j]=idx;
	while(Q.size()){
		int r=Q.front().first, c=Q.front().second;
		island[idx].push_back({r, c});
		Q.pop();
		for(int d=0;d<4;++d){
			int nr=r+dr[d], nc=c+dc[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
			if(arr[nr][nc]==-1){
				arr[nr][nc]=idx;
				Q.push({nr, nc});
			}
		}
	}
	++idx;
}
int bfs(int a, int b, int r, int c, int d){
	int ret=1;
	queue<pii> Q;
	Q.push({r, c});
	while(Q.size()){
		int nr=Q.front().first+dr[d], nc=Q.front().second+dc[d];
		Q.pop();
		if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
		if(arr[nr][nc]==b){
			return ret==1 ? 0:ret;
		}
		else if(arr[nr][nc]>0){
			return 0;
		}
		Q.push({nr, nc});
		ret++;
	}
	return 0;
}
void bridge(int a){
	queue<vec> Q;
	for(pii & v:island[a]){
		for(int d=0;d<4;++d){
			int r=v.first+dr[d], c=v.second+dc[d];
			if(r<0 || r>=N || c<0 || c>=M)	continue;
			if(arr[r][c])	continue;
			Q.push({r, c, d});
		}
	}
	int cnt=0, s, t;
	while(s=Q.size()){
		while(s--){
			int d=Q.front().d;
			int r=Q.front().r+dr[d], c=Q.front().c+dc[d];
			Q.pop();
			if(r<0 || r>=N || c<0 || c>=M)	continue;
			if(t=arr[r][c]){
				if(cnt && ans[a][t]>cnt+1)	ans[a][t]=cnt+1;
			}
			else{
				Q.push({r, c, d});
			}
		}
		cnt++;
	}
}
int sol(int k){
	if(k==K)	return 0;
	int &ret=dp[k];
	if(ret!=-1)	return ret;
	ret=600;
	for(int i=1;i<idx;++i){
		if(!(k&(1<<(i-1))))	continue;
		for(int j=1;j<idx;++j){
			if(k&(1<<j-1))	continue;
			if(ans[i][j]>10)	continue;
			ret=min(ret, sol(k|(1<<(j-1)))+ans[i][j]);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>arr[i][j];
			if(arr[i][j])	arr[i][j]=-1;
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(arr[i][j]==-1)	fisland(i, j);
		}
	}
	for(int i=1;i<idx;++i){
		for(int j=i;j<idx;++j){
			ans[i][j]=ans[j][i]=11;
		}
	}
	K=(1<<(idx-1))-1;
	for(int i=1;i<idx;++i)	bridge(i);
	for(int i=0;i<64;++i)	dp[i]=-1;
	sol(1);
	if(dp[1]<600) cout<<dp[1]<<"\n";
	else	cout<<"-1\n";
	return 0;
}
