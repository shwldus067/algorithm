#include<iostream>
#include<queue>
using namespace std;
int N, L, R, A[52][52];
char adj[52][52];
bool visit[52][52];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>R;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)	cin>>A[i][j];
	for(int i=0;i<=N;++i){
		A[N+1][i]=A[i][N+1]=1000;
	}
	int ans=0;
	queue<pair<int, int> > Q, qu;
	while(1){
		int f=0;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				adj[i][j]=0;
				int d=A[i][j]-A[i+1][j];
				d=d<0?-d:d;
				if(L<=d && d<=R)	adj[i][j]=1, f=1;
				d=A[i][j]-A[i][j+1];
				d=d<0?-d:d;
				if(L<=d && d<=R)	adj[i][j]+=2, f=1;
			}
		}
		if(!f)	break;
		ans++;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(!visit[i][j]){
					Q.push({i, j});
					visit[i][j]=1;
					int sum=0, cnt=0;
					while(Q.size()){
						int r=Q.front().first, c=Q.front().second;
						Q.pop();
						sum+=A[r][c];
						cnt++;
						qu.push({r, c});
						if(adj[r][c]&1 && !visit[r+1][c]){
							visit[r+1][c]=1;
							Q.push({r+1, c});
						}
						if(adj[r][c]&2 && !visit[r][c+1]){
							visit[r][c+1]=1;
							Q.push({r, c+1});
						}
						if(adj[r][c-1]&2 && !visit[r][c-1]){
							visit[r][c-1]=1;
							Q.push({r, c-1});
						}
						if(adj[r-1][c]&1 && !visit[r-1][c]){
							visit[r-1][c]=1;
							Q.push({r-1, c});
						}
					}
					int m=sum/cnt;
					while(qu.size()){
						int r=qu.front().first, c=qu.front().second;
						qu.pop();
						A[r][c]=m;
					}
				}
			}
		}
		for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)	visit[i][j]=0;
	}
	cout<<ans<<"\n";
	return 0;
}
