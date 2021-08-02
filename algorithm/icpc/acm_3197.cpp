#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int R, C, cnt=1;
bool visit[1500][1500];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char arr[1500][1500];
vector<pair<int, int>> L;
queue<pair<int, int> > Q;
queue<pair<int, int> > lq[2];
void bfs(void){
	int cr, cc, nr, nc, size, idx=1, ndx=0;
	while(size=Q.size()){
		while(size--){
			cr=Q.front().first, cc=Q.front().second;
			Q.pop();
			for(int i=0;i<4;i++){
				nr=cr+dr[i], nc=cc+dc[i];
				if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
				if(arr[nr][nc]=='X'){
					arr[nr][nc]='.';
					Q.push({nr, nc});
				}
			}
		}
		idx^=1;
		ndx^=1;
		while(lq[idx].size()){
			cr=lq[idx].front().first, cc=lq[idx].front().second;
			lq[idx].pop();
			visit[cr][cc]=true;
			for(int i=0;i<4;i++){
				nr=cr+dr[i], nc=cc+dc[i];
				if(nr<0 || nr>=R || nc<0 || nc>=C)	continue;
				if(nr==L[1].first && nc==L[1].second)	return;
				if(visit[nr][nc])	continue;
				if(arr[nr][nc]=='.'){
					visit[nr][nc]=true;
					lq[idx].push({nr, nc});
				}
				else{
					visit[nr][nc]=true;
					lq[ndx].push({nr, nc});
				}
			}
		}
		cnt++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	string tp;
	for(int i=0;i<R;i++){
		cin>>arr[i];
		for(int j=0;j<C;j++){
			if(arr[i][j]=='L'){
				L.push_back({i, j});
				arr[i][j]='.';
				Q.push({i, j});
			}
			else if(arr[i][j]=='.'){
				Q.push({i, j});
			}
		}
	}
	lq[0].push({L[0].first, L[0].second});
	bfs();
	cout<<cnt<<"\n";
	return 0;
}
