#include<iostream>
#include<queue>
using namespace std;
int N, M, cnt;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char wall[1000][1000];
int visit[1000][1000], cell[500001];
bool chk(int nr, int nc){
	return nr>=0 && nr<N && nc>=0 && nc<M;
}
void bfs(int r, int c){
	int cr, cc, nr, nc;
	int &ans=cell[cnt];
	queue<pair<int, int> > Q;
	Q.push({r, c});
	visit[r][c]=cnt;
	ans=1;
	while(Q.size()){
		cr=Q.front().first, cc=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=cr+dr[i], nc=cc+dc[i];
			if(!chk(nr, nc) || visit[nr][nc])	continue;
			if(wall[nr][nc]=='0'){
				visit[nr][nc]=cnt;
				Q.push({nr, nc});
				ans++;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>wall[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(wall[i][j]=='0' && visit[i][j]==0){
				cnt++;
				bfs(i, j);
			}
		}
	}
	int num, r, c, s, ch[4]={0,}, idx;
	bool f;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(wall[i][j]=='1'){
				num=1;
				idx=0;
				for(int k=0;k<4;k++){
					r=i+dr[k], c=j+dc[k], s=visit[r][c];
					if(!chk(r, c))	continue;
					if(wall[r][c]=='1')	continue;
					f=false;
					for(int t=0;t<idx;t++)
						if(ch[t]==s){
							f=true;
							break;
						}
					if(f)	continue;
					ch[idx++]=s;
					num+=cell[s];
				}
				cout<<num%10;
			}
			else{
				cout<<'0';
			}
		}
		cout<<"\n";
	}
	return 0;
}
