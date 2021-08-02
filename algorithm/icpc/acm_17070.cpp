#include<iostream>
#include<queue>
using namespace std;
struct pipe{
	int t, r, c;
};
int N, arr[16][16];
int d[3]={2, 2, 3}, dd[3][3]={{0, 2}, {1, 2}, {0, 1, 2}};
int dr[3][3]={{0, 1}, {1, 1}, {0, 1, 1}};
int dc[3][3]={{1, 1}, {0, 1}, {1, 0, 1}};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	queue<pipe> Q;
	Q.push({0, 0, 1});
	int ans=0;
	while(Q.size()){
		int t=Q.front().t, r=Q.front().r, c=Q.front().c;
		Q.pop();
		if(r==N-1 && c==N-1){
			++ans; continue;
		}
		for(int i=0;i<d[t];++i){
			int nr=r+dr[t][i], nc=c+dc[t][i];
			if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
			if(arr[nr][nc])	continue;
			if(dd[t][i]==2 && (arr[nr-1][nc] || arr[nr][nc-1]))	continue;
			Q.push({dd[t][i], nr, nc});
		}
	}
	cout<<ans<<"\n";
	return 0;
}
