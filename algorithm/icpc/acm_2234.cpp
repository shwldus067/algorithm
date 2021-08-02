#include<iostream>
#include<queue>
using namespace std;
int n, m, arr[50][50], visit[50][50], cnt, room[2501], rmax;
int dr[]={0, -1, 0, 1}, dc[]={-1, 0, 1, 0}, smax;
void bfs(int r, int c){
	int cr, cc, nr, nc;
	int ans=1;
	queue<pair<int, int> > Q;
	Q.push({r, c});
	visit[r][c]=cnt;
	while(Q.size()){
		cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			if(arr[cr][cc]&(1<<i))	continue;
			nr=cr+dr[i], nc=cc+dc[i];
			if(visit[nr][nc])	continue;
			visit[nr][nc]=cnt;
			ans++;
			Q.push({nr, nc});
		}
	}
	if(rmax<ans)	rmax=ans;
	room[cnt]=ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(visit[i][j]==0){
				cnt++;
				bfs(i, j);
			}
	int sum, i, j;
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(arr[i][j]&4 && visit[i][j]!=visit[i][j+1]){
				sum=room[visit[i][j]]+room[visit[i][j+1]];
				if(smax<sum)	smax=sum;
			}
			if(arr[i][j]&8 && visit[i][j]!=visit[i+1][j]){
				sum=room[visit[i][j]]+room[visit[i+1][j]];
				if(smax<sum)	smax=sum;
			}
		}
		if(arr[i][j]&8 && visit[i][j]!=visit[i+1][j]){
			sum=room[visit[i][j]]+room[visit[i+1][j]];
			if(smax<sum)	smax=sum;
		}
	}
	for(j=0;j<n-1;j++){
		if(arr[i][j]&2 && visit[i][j]!=visit[i][j+1]){
			sum=room[visit[i][j]]+room[visit[i][j+1]];
			if(smax<sum)	smax=sum;
		}
	}
	cout<<cnt<<"\n"<<rmax<<"\n"<<smax<<"\n";
	return 0;
}
