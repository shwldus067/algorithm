#include<iostream>
using namespace std;
int N, M, row, col;
char arr[50][50];
bool visit[50][50];
bool dfs(int r, int c, int n){
	visit[r][c]=true;
	if(c+1<M && arr[r][c]==arr[r][c+1]){
		if(n>=4 && r==row && c+1==col)	return true;
		if(!visit[r][c+1] && dfs(r, c+1, n+1))	return true;
	}
	if(r+1<N && arr[r][c]==arr[r+1][c]){
		if(n>=4 && r+1==row && c==col)	return true;
		if(!visit[r+1][c] && dfs(r+1, c, n+1))	return true;
	}
	if(c-1>=0 && arr[r][c]==arr[r][c-1]){
		if(n>=4 && r==row && c-1==col)	return true;
		if(!visit[r][c-1] && dfs(r, c-1, n+1))	return true;
	}
	if(r-1>=0 && arr[r][c]==arr[r-1][c]){
		if(n>=4 && r-1==row && c==col)	return true;
		if(!visit[r-1][c] && dfs(r-1, c, n+1))	return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			fill(&visit[0][0], &visit[N-1][M], false);
			row=i, col=j;
			if(dfs(i, j, 1)){
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No\n";
	return 0;
}
