#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, L, sr, sc, er, ec;
	int dr[8]={-1, -2, -2, -1, 1, 2, 2, 1};
	int dc[8]={-2, -1, 1, 2, 2, 1, -1, -2};
	bool visit[300][300];
	queue<pii> Q;
	cin>>T;
	while(T--){
		cin>>L>>sr>>sc>>er>>ec;
		Q=queue<pii>();
		fill(&visit[0][0], &visit[299][300], 0);
		visit[sr][sc]=1;
		Q.push({sr, sc});
		int size, f=0, ans=0;
		while(size=Q.size()){
			while(size--){
				int r=Q.front().first, c=Q.front().second;
				Q.pop();
				if(r==er && c==ec){
					f=1;
					break;
				}
				for(int i=0;i<8;++i){
					int nr=r+dr[i], nc=c+dc[i];
					if(nr<0 || nr>=L || nc<0 || nc>=L)	continue;
					if(visit[nr][nc])	continue;
					visit[nr][nc]=1;
					Q.push({nr, nc});
				}
			}
			if(f)	break;
			++ans;
		}
		cout<<ans<<"\n";
	}
}
