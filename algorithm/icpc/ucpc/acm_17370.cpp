#include<iostream>
using namespace std;
int N;
int dr[6]={1, 1, -1, -1, -1, 1};
int dc[6]={0, 1, 1, 0, -1, -1};
bool visit[100][100];
int dfs(int r, int c, int d, int cnt){
	if(cnt==N){
		if(visit[r][c])	return 1;
		else 	return 0;
	}
	if(visit[r][c])	return 0;
	visit[r][c]=true;
	int d1=(d+5)%6, d2=(d+1)%6;
	int ret1=dfs(r+dr[d1], c+dc[d1], d1, cnt+1);
	int ret2=dfs(r+dr[d2], c+dc[d2], d2, cnt+1);
	visit[r][c]=false;
	return ret1+ret2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	visit[50][50]=true;
	cout<<dfs(51, 50, 0, 0)<<"\n";
	return 0;
}
