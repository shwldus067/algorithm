#include<iostream>
#include<algorithm>
using namespace std;
int par[10000];
int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, ans=0, cnt=0;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	bool chk[100][100];
	pair<int, int> arr[10000];
	cin>>N;
	M=N*N;
	for(int i=0;i<M;++i){
		cin>>arr[i].first;
		arr[i].second=par[i]=i;
	}
	sort(arr, arr+M);
	for(int i=M-1;i>=0;--i){
		cnt++;
		int r=arr[i].second/N, c=arr[i].second%N;
		chk[r][c]=1;
		for(int d=0;d<4;++d){
			int nr=r+dr[d], nc=c+dc[d], j=nr*N+nc;
			if(nr>=0 && nr<N && nc>=0 && nc<N && chk[nr][nc] 
				&& find(j)!=find(arr[i].second)){
				--cnt;
				par[find(j)]=find(arr[i].second);
			}
		}
		if(!i || arr[i-1].first!=arr[i].first)
			ans=max(ans, cnt);
	}
	cout<<ans<<"\n";
}
