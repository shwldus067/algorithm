#include<stdio.h>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > pip;
int main(){
	bool d[50][50][32]={0, };
	char arr[50][50], cnt=0;
	int N, M, sr, sc, sz, ans=1, end;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	scanf("%d %d", &N, &M);
	for(int i=0;i<M;++i){
		scanf("%s", arr[i]);
		for(int j=0;j<N;++j){
			if(arr[i][j]=='S')	sr=i, sc=j;
			else if(arr[i][j]=='X')	arr[i][j]=cnt++;
		}
	}
	end=(1<<cnt)-1;
	queue<pip> Q;
	Q.push({0, {sr, sc}});
	d[0][sr][sc]=1;
	while(sz=Q.size()){
		while(sz--){
			int v=Q.front().first;
			int r=Q.front().second.first, c=Q.front().second.second;
			Q.pop();
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i], nv=v;
				if(nr<0 || nr>=M || nc<0 || nc>=N)	continue;
				if(arr[nr][nc]=='#')	continue;
				if(arr[nr][nc]=='E' && v==end){
					printf("%d\n", ans);
					return 0;
				}
				if(arr[nr][nc]<cnt)	nv|=(1<<arr[nr][nc]);
				if(d[nr][nc][nv])	continue;
				d[nr][nc][nv]=1;
				Q.push({nv, {nr, nc}});
			}
		}
		++ans;
	}
	return 0;
}
