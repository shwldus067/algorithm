#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int r, c, t, chk;
	bool operator<(const node &a)const{
		return a.t<t;
	};
};
int N, M, arr[10][10], K;
bool visit[10][10][2];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &arr[i][j]);
	K=N-1;
	priority_queue<node> pq;
	pq.push({0, 0, 0, 0});
	while(pq.size()){
		node cur=pq.top();pq.pop();
		if(visit[cur.r][cur.c][cur.chk])	continue;
		visit[cur.r][cur.c][cur.chk]=1;
		if(cur.r==K && cur.c==K){
			printf("%d\n", cur.t);
			return 0;
		}
		cur.t++;
		for(int i=0;i<4;++i){
			int nr=cur.r+dr[i], nc=cur.c+dc[i], nt;
			if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
			if(visit[nr][nc][cur.chk])	continue;
			if(arr[nr][nc]!=1 && arr[cur.r][cur.c]!=1)	continue;
			if(!arr[nr][nc] && cur.chk==0){
				nt=cur.t/M;
				if(cur.t%M)	++nt;
				pq.push({nr, nc, nt*M, 1});
			}
			else if(arr[nr][nc]){
				nt=cur.t/arr[nr][nc];
				if(cur.t%arr[nr][nc])	++nt;
				pq.push({nr, nc, nt*arr[nr][nc], cur.chk});
			}
		}
	}
	return 0;
}
