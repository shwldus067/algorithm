#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int w, h;
char room[20][21];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
pii point[11];
int dist[11][11];
void bfs(int k){
	bool visit[20][20]={0, };
	int cnt=1, size;
	queue<pii> Q;
	Q.push(point[k]);
	visit[point[k].first][point[k].second]=1;
	while(size=Q.size()){
		while(size--){
			int r=Q.front().first, c=Q.front().second;
			Q.pop();
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=h || nc<0 || nc>=w)	continue;
				if(room[nr][nc]=='x')	continue;
				if(visit[nr][nc])	continue;
				else if(room[nr][nc]<11){
					dist[k][room[nr][nc]]=cnt;
				}
				visit[nr][nc]=1;
				Q.push({nr, nc});
			}
		}
		++cnt;
	}
}
int main(){
	while(1){
		scanf("%d %d", &w, &h);
		if(w==0 && h==0)	break;
		int pcnt=1, per[10];
		char c;
		for(int i=0;i<h;++i){
			scanf("%s", &room[i]);
			for(int j=0;j<w;++j){
				c=room[i][j];
				if(c=='o')	point[0]={i, j};
				if(c=='*')	point[pcnt]={i, j}, room[i][j]=pcnt++;
			}
		}
		if(pcnt==1){
			printf("0\n");
			continue;
		}
		fill(&dist[0][0], &dist[10][11], 0);
		for(int i=0;i<pcnt;++i)	bfs(i);
		for(int i=1;i<pcnt;++i)		per[i-1]=i;
		int ans=1e6, sum;
		pcnt--;
		do{
			if(sum=dist[0][per[0]]){
				int flag=1;
				for(int i=1;i<pcnt;++i){
					if(!dist[per[i-1]][per[i]]){
						flag=0;break;
					}
					sum+=dist[per[i-1]][per[i]];
				}
				if(flag && ans>sum)	ans=sum;
			}
		}while(next_permutation(per, per+pcnt));
		if(ans==1e6)	printf("-1\n");
		else	printf("%d\n", ans);
	}
	return 0;
}
