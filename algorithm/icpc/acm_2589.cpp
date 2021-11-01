#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, ans, fr, re;
	pii Q[2500];
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	char arr[52][52];
	bool visit[52][52]={0, };
	cin>>N>>M;
	for(int i=1;i<=N;++i)	cin>>arr[i]+1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			if(arr[i][j]!='L')	continue;
			if(arr[i+1][j]=='L' && arr[i-1][j]=='L')	continue;
			if(arr[i][j+1]=='L' && arr[i][j-1]=='L')	continue;
			for(int k=1;k<=N;++k)for(int l=1;l<=M;++l)	visit[k][l]=0;
			fr=re=0;
			Q[re++]={i, j};
			visit[i][j]=1;
			int cnt=0;
			while(int size=re-fr){
				while(size--){
					int r=Q[fr].first, c=Q[fr++].second;
					if(arr[r-1][c]=='L' && !visit[r-1][c])	visit[r-1][c]=1, Q[re++]={r-1, c};
					if(arr[r][c+1]=='L' && !visit[r][c+1])	visit[r][c+1]=1, Q[re++]={r, c+1};
					if(arr[r+1][c]=='L' && !visit[r+1][c])	visit[r+1][c]=1, Q[re++]={r+1, c};
					if(arr[r][c-1]=='L' && !visit[r][c-1])	visit[r][c-1]=1, Q[re++]={r, c-1};
				}
				++cnt;
			}
			ans=max(ans, cnt);
		}
	}
	cout<<ans-1<<"\n";
	return 0;
}
