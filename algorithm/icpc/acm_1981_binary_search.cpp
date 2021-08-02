#include<iostream>
#include<queue>
using namespace std;
int N, arr[100][100], a, b, mm, MM;
int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
bool visit[100][100];
bool dfs(int r, int c, int m, int M){
	if(r<0 || c<0 || r>=N || c>=N || visit[r][c] || arr[r][c]<m || arr[r][c]>M)
		return false;
	visit[r][c]=true;
	if(r==N-1 && c==N-1)	return true;
	for(int i=0;i<4;++i)
		if(dfs(r+dr[i], c+dc[i], m, M))	return true;
	return false;
}
int sol(int mid){
	int m=b-mid<mm ? mm:b-mid;
	int M=a>MM-mid ? MM-mid:a;
	for(int k=m;k<=M;++k){
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)	visit[i][j]=0;
		if(dfs(0, 0, k, k+mid))	return true;
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
	if(arr[0][0]<arr[N-1][N-1])	a=arr[0][0], b=arr[N-1][N-1];
	else	a=arr[N-1][N-1], b=arr[0][0];
	int l=b-a, r=MM-mm, ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(sol(mid))	r=mid-1, ans=mid;
		else	l=mid+1;
	}
	cout<<ans<<"\n";
	return 0;
}
