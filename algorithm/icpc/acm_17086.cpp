#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[50][50];
int dr[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8]={-1, 0, 1, 1, 1, 0, -1, -1};
bool visit[50][50];
queue<pii> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				Q.push({i, j});
				visit[i][j]=1;
			}
		}
	}
	int cnt=1, size;
	while(size=Q.size()){
		while(size--){
			int r=Q.front().first, c=Q.front().second;
			Q.pop();
			for(int i=0;i<8;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
				if(visit[nr][nc])	continue;
				Q.push({nr, nc});
				visit[nr][nc]=1;
			}
		}
		cnt++;
	}
	cout<<cnt-2<<"\n";
	return 0;
}
