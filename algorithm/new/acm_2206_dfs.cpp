#include<iostream>
using namespace std;

int route[1002][1002];
bool visit[1002][1002];
int N, M;
int len=1000000;

int dr[4]={-1, 1, 0, 0};
int dc[4]={0, 0, -1, 1};

void dfs(int r, int c, int cnt, bool flag){
	int row, col;
	visit[r][c]=true;
	if(r==N && c==M){
		if(cnt<len)
			len=cnt;
		visit[r][c]=false;
		return;
	}
	
	for(int i=0;i<4;i++){
		row=r+dr[i];
		col=c+dc[i];
		if(route[row][col]==0 && visit[row][col]==false)
			dfs(row, col, cnt+1, flag);
		else if(route[row][col]==1 && visit[row][col]==false && flag==false)
			dfs(row, col, cnt+1, true);
	}
	
	visit[r][c]=false;
	return;
}

int main(){
	int i, j;
	char tmp;
	cin>>N>>M;
	
	fill(&route[0][0], &(route[N+1][M+2]), 2);
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			cin>>tmp;
			route[i][j]=tmp-48;
		}
	}
	fill(&visit[0][0], &(visit[N+1][M+2]), false);
	
	dfs(1, 1, 1, false);
	if(len==1000000)	cout<<-1;
	else	cout<<len;
	
	return 0;
}
