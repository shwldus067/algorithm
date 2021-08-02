#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int tc, w, h;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
char arr[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	while(tc--){
		queue<pii> Q;
		queue<pii> qu;
		cin>>w>>h;
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				cin>>arr[i][j];
				if(arr[i][j]=='@')	Q.push({i, j});
				else if(arr[i][j]=='*')	qu.push({i, j});
			}
		}
		int s, size, ans=1, find=0;
		while(s=Q.size()){
			int r, c, nr, nc;
			size=qu.size();
			while(size--){
				r=qu.front().first, c=qu.front().second;
				qu.pop();
				for(int i=0;i<4;++i){
					nr=r+dr[i], nc=c+dc[i];
					if(nr<0 || nr>=h || nc<0 || nc>=w)	continue;
					if(arr[nr][nc]=='.'){
						arr[nr][nc]='*';
						qu.push({nr, nc});
					}
				}
			}
			while(s--){
				r=Q.front().first, c=Q.front().second;
				Q.pop();
				for(int i=0;i<4;++i){
					nr=r+dr[i], nc=c+dc[i];
					if(nr<0 || nr>=h || nc<0 || nc>=w){
						find=1;break;
					}
					if(arr[nr][nc]=='.'){
						arr[nr][nc]='@';
						Q.push({nr, nc});
					}
				}
				if(find)	break;
			}
			if(find)	break;
			ans++;
		}
		if(find)	cout<<ans<<"\n";
		else	cout<<"IMPOSSIBLE\n";
	}
}
