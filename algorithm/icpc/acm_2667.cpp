#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N;
char arr[25][25];
bool visit[25][25];
int bfs(int r, int c){
	queue<pii> Q;
	Q.push({r, c});
	visit[r][c]=1;
	int ret=0;
	while(Q.size()){
		int rr=Q.front().first, cc=Q.front().second;
		Q.pop();
		ret++;
		for(int i=0;i<4;++i){
			int nr=rr+"2101"[i]-'1', nc=cc+"1210"[i]-'1';
			if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
			if(arr[nr][nc]=='0')	continue;
			if(visit[nr][nc])	continue;
			visit[nr][nc]=1;
			Q.push({nr, nc});
		}
	}
	return ret;
}
int main(){
	int ans[400], cnt=0;
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%s", &arr[i]);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(arr[i][j]=='0')	continue;
			if(visit[i][j])	continue;
			ans[cnt++]=bfs(i, j);
		}
	}
	sort(ans, ans+cnt);
	printf("%d\n", cnt);
	for(int i=0;i<cnt;++i)	printf("%d\n", ans[i]);
	return 0;
}
