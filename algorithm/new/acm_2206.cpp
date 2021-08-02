#include<iostream>
#include<queue>
using namespace std;

int route[1002][1002];
bool visit[1002][1002][2];
int N, M;

queue<pair<pair<int, int>, bool> > Q;
int dr[4]={-1, 1, 0, 0};
int dc[4]={0, 0, -1, 1};

int bfs(){
	int r=1, c=1, row, col;
	int cnt[N+1][M+1];
	bool flag;
	
	fill(&cnt[0][0], &cnt[N][M+1], 0);
	cnt[1][1]=1;
	visit[r][c][0]=true;
	Q.push(make_pair(make_pair(1, 1), false));
	
	while(!Q.empty()){
		r=Q.front().first.first;
		c=Q.front().first.second;
		flag=Q.front().second;
		Q.pop();
		
		if(r==N && c==M){
			return cnt[r][c];
		}
		
		for(int i=0;i<4;i++){
			row=r+dr[i];
			col=c+dc[i];
			if(route[row][col]==0 && visit[row][col][flag]==false){
				Q.push(make_pair(make_pair(row, col), flag));
				visit[row][col][flag]=true;
				cnt[row][col]=cnt[r][c]+1;
			}
			else if(route[row][col]==1 && visit[row][col][flag]==false && flag==false){
				Q.push(make_pair(make_pair(row, col), true));
				visit[row][col][flag]=true;
				cnt[row][col]=cnt[r][c]+1;
			}
		}
	}
	return -1;
}

int main(){
	int i, j;
	char tmp;
	cin>>N>>M;
	
	fill(&route[0][0], &route[N+1][M+2], 2);
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			cin>>tmp;
			route[i][j]=tmp-48;
		}
	}
	fill(&visit[0][0][0], &(visit[N+1][M+1][2]), false);
	
	cout<<bfs();
	
	return 0;
}
