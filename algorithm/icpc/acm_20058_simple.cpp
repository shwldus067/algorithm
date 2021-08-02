#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[66][66], sum, ans;
int A[7]={1, 2, 4, 8, 16, 32, 64};
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool visit[66][66];
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
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		cin>>arr[i][j];
	}
	queue<pii> Q;
	while(M--){
		int L;
		cin>>L;
		L=A[L];
		if(L>1)
			for(int i=1;i<=N;i+=L){
				for(int j=1;j<=N;j+=L){
					rot(i, j, L);
				}
			}
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(!arr[i][j])	continue;
				int cnt=(arr[i-1][j] ? 1:0)+(arr[i+1][j] ? 1:0)+
						(arr[i][j-1] ? 1:0)+(arr[i][j+1] ? 1:0);
				if(cnt<3)	Q.push({i, j});
			}
		}
		while(Q.size()){
			arr[Q.front().first][Q.front().second]--;Q.pop();
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
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
