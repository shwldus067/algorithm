#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[10][10], chk[10][10], idx, p[7], ans;
int dr[4]={-1, 1, 0, 0}, dc[4]={0, 0, -1, 1};
priority_queue<tuple<int, int, int> > pq;
void bfs(int x, int y){
	queue<pii> Q;
	Q.push({x, y});
	chk[x][y]=idx;
	while(Q.size()){
		int r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(int d=0;d<4;++d){
			int nr=r+dr[d], nc=c+dc[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
			if(arr[nr][nc] && !chk[nr][nc]){
				chk[nr][nc]=idx;
				Q.push({nr, nc});
			}
		}
	}
}
int parent(int a){
	return a==p[a] ? a:parent(p[a]);
}
pii sol(int r, int c, int d){
	if(r<0 || r>=N || c<0 || c>=M)	return {0, 0};
	if(chk[r][c])	return {chk[r][c], 0};
	pii tmp=sol(r+dr[d], c+dc[d], d);
	++tmp.second;
	return tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	cin>>arr[i][j];
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)
		if(arr[i][j] && !chk[i][j])	idx++, bfs(i, j);
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)
		if(!arr[i][j]){
			for(int k=0;k<2;++k){
				pii a=sol(i, j, k+k);
				pii b=sol(i, j, k+k+1);
				if(a.first && b.first && a.second+b.second>2)
					pq.push(make_tuple(-a.second-b.second+1, a.first, b.first));
			}
		}
	for(int i=1;i<=idx;++i)	p[i]=i;
	while(pq.size()){
		int k, a, b;
		tie(k, a, b)=pq.top();pq.pop();
		if(parent(a)!=parent(b)){
			ans-=k;
			p[parent(a)]=p[parent(b)];
		}
	}
	for(int i=1;i<=idx;++i)if(parent(1)!=parent(i)){
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<"\n";
	return 0;
}
