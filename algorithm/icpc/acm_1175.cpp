#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct str{
	int r, c, d;
	str(){}
	str(int r, int c, int d):r(r), c(c), d(d){}
};
const int inf=~(1<<31);
int N, M, ans;
char arr[50][50];
int res[2][4];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
vector<pair<int, int> > v;
void bfs(int start, int end, int dir){
	int r, c, d, num, nr, nc, size, cnt=1;
	str cur(v[start].first, v[start].second, dir);
	queue<str> Q;
	Q.push(cur);
	int visit[50][50][4]={0, };
	while(size=Q.size()){
		while(size--){
			cur=Q.front();
			r=cur.r, c=cur.c, d=cur.d;
			Q.pop();
			for(int i=0;i<4;i++){
				if(i==d)	continue;
				nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
				if(visit[nr][nc][i])	continue;
				if(arr[nr][nc]=='#')	continue;
				visit[nr][nc][i]=cnt;
				Q.push(str(nr, nc, i));
			}
		}
		cnt++;
	}
	for(int i=0;i<4;i++){
		res[end][i]=visit[v[end].first][v[end].second][i];
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int sr, sc;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		for(int j=0;j<M;j++){
			if(arr[i][j]=='C'){
				v.push_back({i, j});
			}
			else if(arr[i][j]=='S'){
				sr=i, sc=j;
			}
		}
	}
	v.push_back({sr, sc});
	ans=inf;
	int fir, sec;
	for(int s=0;s<=1;s++){
		for(int i=0;i<4;i++)	res[0][i]=res[1][i]=0;
		bfs(2, s, -1);
		for(int i=0;i<4;i++)
			if(res[s][i]){
				bfs(s, s^1, i);
				for(int j=0;j<4;j++)
					if(res[s^1][j])
						ans=min(ans, res[s][i]+res[s^1][j]);
			}
	}
	if(ans==inf)	cout<<"-1\n";
	else	cout<<ans<<"\n";
	return 0;
}
