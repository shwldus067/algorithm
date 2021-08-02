#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[2][20][20], t=0;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int R, C, RB, G;
bool chk[20][20];
void gravity(){
	int loc;
	for(int j=0;j<N;++j){
		loc=N-1;
		for(int i=N-1;i>=0;--i){
			if(arr[t][i][j]==-1)	loc=i-1;
			else if(arr[t][i][j]>=0){
				if(i==loc){
					loc--;
					continue;
				}
				arr[t][loc][j]=arr[t][i][j];
				arr[t][i][j]=-2;
				loc--;
			}
		}
	}
}
void rotate(){
	int nt=t^1;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		arr[nt][N-1-j][i]=arr[t][i][j];
	}
}
void bfs(int i, int j){
	bool visit[20][20]={0, };
	int cnt=1, color=arr[t][i][j], rb=0;
	int rr=i, cc=j;
	queue<pii> Q;
	visit[i][j]=1;
	chk[i][j]=1;
	Q.push({i, j});
	while(Q.size()){
		int r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(int d=0;d<4;++d){
			int nr=r+dr[d], nc=c+dc[d];
			if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
			if(visit[nr][nc])	continue;
			if(arr[t][nr][nc]==0 || arr[t][nr][nc]==color){
				visit[nr][nc]=1;
				Q.push({nr, nc});
				++cnt;
				rb+=!arr[t][nr][nc];
				if(arr[t][nr][nc]){
					chk[nr][nc]=1;
					if(nr<rr || (nr==rr && nc<cc))	rr=nr, cc=nc;
				}
			}
		}
	}
	if(G<cnt || (G==cnt && (RB<rb || (RB==rb && (R<rr || (R==rr && C<cc)))))){
		R=rr;C=cc;G=cnt;RB=rb;
	}
}
void erase(){
	int color=arr[t][R][C];
	queue<pii> Q;
	Q.push({R, C});
	arr[t][R][C]=-2;
	while(Q.size()){
		int r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(int d=0;d<4;++d){
			int nr=r+dr[d], nc=c+dc[d];
			if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
			if(arr[t][nr][nc]==0 || arr[t][nr][nc]==color){
				Q.push({nr, nc});
				arr[t][nr][nc]=-2;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>arr[0][i][j];
	int ans=0;
	while(1){
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)	chk[i][j]=0;
		R=C=RB=G=-1;
		for(int i=N-1;i>=0;--i){
			for(int j=N-1;j>=0;--j){
				if(arr[t][i][j]>0 && !chk[i][j]){
					bfs(i, j);
				}
			}
		}
		if(G<2)	break;
		erase();
		gravity();
		rotate();
		t^=1;
		gravity();
		ans+=G*G;
	}
	cout<<ans<<"\n";
	return 0;
}
