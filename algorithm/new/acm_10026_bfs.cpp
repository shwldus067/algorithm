#include<iostream>
#include<queue>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
char ary[101][101];
bool visit[101][101];

void bfs(int i, int j){
	queue<pair<int, int> > Q;
	char color=ary[i][j];
	int a, b;
	Q.push(make_pair(i, j));
	visit[i][j]=true;
	while(!Q.empty()){
		a=Q.front().first;
		b=Q.front().second;
		Q.pop();
		for(int k=0;k<4;k++){
			if(ary[a+dy[k]][b+dx[k]]==color && visit[a+dy[k]][b+dx[k]]==false){
				visit[a+dy[k]][b+dx[k]]=true;
				Q.push(make_pair(a+dy[k], b+dx[k]));
			}
		}
	}
}
int main(){
	int N, cnt=0, cnt_b=0;
	cin>>N;
	fill(&visit[0][0], &visit[N][N+1], false);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>ary[i][j];
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(visit[i][j]==false){
				bfs(i, j);
				cnt++;
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(ary[i][j]=='G'){
				ary[i][j]='R';
			}
		}
	}
	fill(&visit[0][0], &visit[N][N+1], false);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(visit[i][j]==false){
				bfs(i, j);
				cnt_b++;
			}
		}
	}
	
	cout<<cnt<<" "<<cnt_b;
	return 0;
}
