#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > piii;
string maze[50];
int dist[50][50][1<<6];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, 1, -1};
const int inf=(1<<31)-1;
int n, m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int sx, sy;
	for(int i=0;i<n;i++){
		cin>>maze[i];
		for(int j=0;j<m;j++){
			if(maze[i][j]=='0')	sx=i, sy=j;
			for(int k=0;k<(1<<6);k++){
				dist[i][j][k]=inf;
			}
		}
	}
	queue<piii> Q;
	dist[sx][sy][0]=0;
	Q.push({sx, {sy, 0}});
	while(Q.size()){
		int x=Q.front().first;
		int y=Q.front().second.first;
		int key=Q.front().second.second;
		Q.pop();
		for(int d=0;d<4;d++){
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(0>nx || nx>=n)	continue;
			if(0>ny || ny>=m)	continue;
			if(maze[nx][ny]=='#')	continue;
			if(maze[nx][ny]=='1'){
				cout<<dist[x][y][key]+1;
				return 0;
			}
			if('A'<=maze[nx][ny] && maze[nx][ny]<='F'){
				int dr=(1<<(maze[nx][ny]-'A'));
				if(key & dr){
					if(dist[nx][ny][key]!=inf)	continue;
					dist[nx][ny][key]=dist[x][y][key]+1;
					Q.push({nx, {ny, key}});
				}
			}
			else{
				int nk=key;
				if('a'<=maze[nx][ny] && maze[nx][ny]<='f'){
					int k=(1<<(maze[nx][ny]-'a'));
					nk|=k;
				}
				if(dist[nx][ny][nk]!=inf)	continue;
				dist[nx][ny][nk]=dist[x][y][key]+1;
				Q.push({nx, {ny, nk}});
			}
		}
	}
	cout<<-1<<"\n";
	return 0;
}
