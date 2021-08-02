#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[64][64], sum, ans;
int A[7]={1, 2, 4, 8, 16, 32, 64};
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int visit[64][64], chk[64][64];
void rot(int r, int c, int n){
	for(int i=n-1;i>0;i-=2){
		for(int j=i;j>0;--j){
			int tmp=arr[r][c+j];
			arr[r][c+j]=arr[r+i-j][c];
			arr[r+i-j][c]=arr[r+i][c+i-j];
			arr[r+i][c+i-j]=arr[r+j][c+i];
			arr[r+j][c+i]=tmp;
		}
		r++, c++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	N=A[N];
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		cin>>arr[i][j];
	}
	while(M--){
		int L;
		cin>>L;
		L=A[L];
		if(L>1)
			for(int i=0;i<N;i+=L){
				for(int j=0;j<N;j+=L){
					rot(i, j, L);
				}
			}
		for(int i=0;i<N;++i){
			visit[0][i]=visit[i][0]=visit[N-1][i]=visit[i][N-1]=1;
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(!arr[i][j] && !chk[i][j]){
					for(int d=0;d<4;++d){
						int r=i+dr[d], c=j+dc[d];
						if(r<0 || r>=N || c<0 || c>=N)	continue;
						if(chk[r][c])	continue;
						if(visit[r][c] && arr[r][c]){
							--arr[r][c];chk[r][c]=1;
						}
						else	visit[r][c]=1;
					}
				}
			}
		}
		if(!chk[0][0] && arr[0][0])	--arr[0][0];
		if(!chk[0][N-1] && arr[0][N-1]) --arr[0][N-1];
		if(!chk[N-1][0] && arr[N-1][0])	--arr[N-1][0];
		if(!chk[N-1][N-1] && arr[N-1][N-1])	--arr[N-1][N-1];
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)	visit[i][j]=chk[i][j]=0;
	}
	queue<pii> Q;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(!visit[i][j] && arr[i][j]){
				Q.push({i, j});
				int cnt=0;
				visit[i][j]=1;
				while(Q.size()){
					int r=Q.front().first, c=Q.front().second;
					cnt++;
					sum+=arr[r][c];
					Q.pop();
					for(int d=0;d<4;++d){
						int nr=r+dr[d], nc=c+dc[d];
						if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
						if(!visit[nr][nc] && arr[nr][nc]){
							visit[nr][nc]=1;
							Q.push({nr, nc});
						}
					}
				}
				if(ans<cnt)	ans=cnt;
			}
		}
	}
	cout<<sum<<"\n"<<ans<<"\n";
	return 0;
}
