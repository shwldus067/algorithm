#include<iostream>
#include<queue>
using namespace std;
#define r first.first
#define c first.second
#define k second
int N, M, K;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char wall[1000][1000];
int visit[1000][1000];
bool chk(int nr, int nc){
	return nr>=0 && nr<N && nc>=0 && nc<M;
}
int bfs(){
	queue<pair<pair<int, int>, int> > Q;
	Q.push({{0, 0}, 0});
	int cr, cc, ck, nr, nc, cnt=1, size;
	bool ch;
	visit[0][0]=0;
	while(size=Q.size()){
		while(size--){
			cr=Q.front().r, cc=Q.front().c, ck=Q.front().k;
			Q.pop();
			if(cr==N-1 && cc==M-1){
				return cnt;
			}
			ch=false;
			for(int i=0;i<4;i++){
				nr=cr+dr[i], nc=cc+dc[i];
				if(!chk(nr, nc) || visit[nr][nc]<=ck)	continue;
				if(wall[nr][nc]=='0'){
					visit[nr][nc]=ck;
					Q.push({{nr, nc}, ck});
				}
				else if(ck<K){
					if(cnt&1){
						visit[nr][nc]=ck+1;
						Q.push({{nr, nc}, ck+1});
					}
					else{
						ch=true;
					}
				}
			}
			if(ch)	Q.push({{cr, cc}, ck});
		}
		cnt++;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>wall[i][j];
		}
	}
	fill(&visit[0][0], &visit[N-1][M], K+1);
	cout<<bfs()<<"\n";
	return 0;
}
