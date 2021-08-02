#include<iostream>
using namespace std;

bool connected[101][101];
bool visited[101];
int N;
int dfs(int s){
	int cnt=1;
	if(visited[s])	return 0;
	visited[s]=true;
	for(int i=1;i<=N;i++){
		if(connected[s][i]){
			cnt+=dfs(i);
		}
	}
	return cnt;
}

int main(){
	int net, cnt=0, n, m;
	cin>>N>>net;
	fill(&connected[0][0], &connected[N][N+1], false);
	fill(&visited[0], &visited[N+1], false);
	for(int i=0;i<net;i++){
		cin>>n>>m;
		connected[n][m]=true;
		connected[m][n]=true;
	}
	cout<<dfs(1)-1;
	
	return 0;
}

