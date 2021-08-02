#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int R, C;
char arr[50][50];
bool visit[50][50];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
queue<pii> Q;
queue<pii> qu;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;++i)for(int j=0;j<C;++j){
		cin>>arr[i][j];
		if(arr[i][j]=='*')	qu.push({i, j});
		else if(arr[i][j]=='S')	Q.push({i, j}), visit[i][j]=true, arr[i][j]='.';
	}
	int s, ans=1, f=0;
	while(s=Q.size()){
		int size=qu.size();
		while(size--){
			int r=qu.front().first, c=qu.front().second;
			qu.pop();
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
				if(arr[nr][nc]=='.'){
					qu.push({nr, nc});
					arr[nr][nc]='*';
				}
			}
		}
		while(s--){
			int r=Q.front().first, c=Q.front().second;
			Q.pop();
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
				if(arr[nr][nc]=='D'){
					f=1;break;
				}
				if(arr[nr][nc]=='.' && !visit[nr][nc]){
					Q.push({nr, nc});
					visit[nr][nc]=true;
				}
			}
			if(f)	break;
		}
		if(f)	break;
		++ans;
	}
	if(f) cout<<ans<<"\n";
	else	cout<<"KAKTUS\n";
	return 0;
}
