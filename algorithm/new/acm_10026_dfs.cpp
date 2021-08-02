#include<iostream>
using namespace std;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
char ary[101][101];
bool visit[101][101];
void dfs(int i, int j){
	char color=ary[i][j];
	for(int k=0;k<4;k++){
		if(ary[i+dy[k]][j+dx[k]]==color && visit[i+dy[k]][j+dx[k]]==false){
			visit[i+dy[k]][j+dx[k]]=true;
			dfs(i+dy[k], j+dx[k]);
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
				dfs(i, j);
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
				dfs(i, j);
				cnt_b++;
			}
		}
	}
	
	cout<<cnt<<" "<<cnt_b;
	return 0;
}
