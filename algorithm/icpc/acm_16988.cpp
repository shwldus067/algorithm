#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[20][20], r[400], c[400], cnt=0, ans=0, x[2], y[2];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
void sol(){
	bool visit[20][20]={0, };
	arr[x[0]][y[0]]=arr[x[1]][y[1]]=1;
	queue<pii> Q;
	int r, c, nr, nc, flag, sum, res=0;
	for(int k=0;k<2;++k){
		for(int i=0;i<4;++i){
			r=x[k]+dr[i];c=y[k]+dc[i];
			if(r<0 || r>=N || c<0 || c>=M)	continue;
			if(arr[r][c]==2 && !visit[r][c]){
				Q.push({r, c});
				visit[r][c]=1;
				flag=sum=0;
				while(Q.size()){
					pii cur=Q.front();Q.pop();
					sum++;
					for(int d=0;d<4;++d){
						nr=cur.first+dr[d];nc=cur.second+dc[d];
						if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
						if(arr[nr][nc]==0){
							flag=1;
							continue;
						}
						else if(arr[nr][nc]==1)	continue;
						if(visit[nr][nc])	continue;
						visit[nr][nc]=1;
						Q.push({nr, nc});
					}
				}
				if(!flag){
					res+=sum;
				}
				Q=queue<pii>();
			}
		}
	}
	ans=max(ans, res);
	arr[x[0]][y[0]]=arr[x[1]][y[1]]=0;
}
void select(int idx, int n){
	if(n==2){
		sol();
		return;
	}
	if(n==cnt)	return;
	for(int i=idx;i<cnt;++i){
		x[n]=r[i];y[n]=c[i];
		select(i+1, n+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		cin>>arr[i][j];
		if(arr[i][j]==0){
			r[cnt]=i;c[cnt++]=j;
		}
	}
	select(0, 0);
	cout<<ans<<"\n";
	return 0;
}
