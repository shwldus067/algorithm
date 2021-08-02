#include<iostream>
using namespace std;
int N, arr[100][100], mm=200, MM;
int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
bool visit[100][100];
bool dfs(int r, int c){
	if(r==N-1 && c==N-1)	return true;
	visit[r][c]=1;
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
		if(visit[nr][nc])	continue;
		if(arr[nr][nc]<mm || arr[nr][nc]>MM)	continue;
		if(dfs(nr, nc))	return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
			mm=min(mm, arr[i][j]);
			MM=max(MM, arr[i][j]);
		}
	}
	int res=MM-mm, last=MM;
	MM=arr[0][0];
	while(mm<=arr[0][0] && MM<=last){
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)	visit[i][j]=0;
		if(dfs(0, 0)){
			res=min(res, MM-mm);
			mm++;
		}
		else	MM++;
	}
	cout<<res<<"\n";
	return 0;
}
