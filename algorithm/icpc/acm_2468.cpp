#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, ans=1, arr[102][102]={0, };
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	bool visit[102][102];
	vector<pii> H[101];
	cin>>N;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		cin>>arr[i][j];
		H[arr[i][j]].push_back({i, j});
	}
	for(int i=1;i<101;++i){
		if(H[i].size()==0)	continue;
		for(pii h:H[i]){
			arr[h.first][h.second]=0;
		}
		for(int r=1;r<=N;++r)for(int c=1;c<=N;++c)	visit[r][c]=0;
		int cnt=0;
		for(int r=1;r<=N;++r)for(int c=1;c<=N;++c){
			if(arr[r][c]==0)	continue;
			if(visit[r][c])	continue;
			queue<pii> Q;
			Q.push({r, c});
			visit[r][c]=1;
			while(Q.size()){
				int rr=Q.front().first, cc=Q.front().second;
				Q.pop();
				for(int d=0;d<4;++d){
					int nr=rr+dr[d], nc=cc+dc[d];
					if(arr[nr][nc]==0)	continue;
					if(visit[nr][nc])	continue;
					Q.push({nr, nc});
					visit[nr][nc]=1;
				}
			}
			++cnt;
		}
		ans=max(ans, cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
