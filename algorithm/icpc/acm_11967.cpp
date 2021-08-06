#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, x, y, a, b;
	vector<pii> arr[101][101];
	cin>>N>>M;
	while(M--){
		cin>>x>>y>>a>>b;
		arr[x][y].push_back({a, b});
	}
	int ans=1;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
	bool chk[101][101]={0, }, light[101][101]={0, }, conn[101][101]={0, };
	chk[1][1]=1;
	light[1][1]=1;
	queue<pii> Q;
	Q.push({1, 1});
	while(Q.size()){
		int r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(pii p:arr[r][c]){
			if(!light[p.first][p.second]){
				light[p.first][p.second]=1, ans++;
				if(conn[p.first][p.second]){
					chk[p.first][p.second]=1;
					Q.push({p.first, p.second});
				}
			}
		}
		for(int i=0;i<4;++i){
			int nr=r+dr[i], nc=c+dc[i];
			if(nr<=0 || nr>N || nc<=0 || nc>N)	continue;
			if(chk[nr][nc])	continue;
			if(!light[nr][nc]){
				conn[nr][nc]=1;
				continue;
			}
			chk[nr][nc]=1;
			Q.push({nr, nc});
		}
	}
	cout<<ans<<"\n";
	return 0;
}
