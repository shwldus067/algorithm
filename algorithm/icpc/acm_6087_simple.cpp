#include<iostream>
#include<queue>
using namespace std;
#define r first.first
#define c first.second
#define s second
int W, H, res[100][100];
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
bool wall[100][100];
pair<int, int> point[2];
bool chk(int nr, int nc){
	return nr>=0 && nr<H && nc>=0 && nc<W;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>W>>H;
	char t;
	int cnt=0;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++){
			cin>>t;
			if(t=='*')	wall[i][j]=1;
			else if(t=='C'){
				point[cnt++]={i, j};
			}
		}
	queue<pair<pair<int, int>, int> > Q;
	fill(&res[0][0], &res[H-1][W], -1);
	int cr, cc, cs, nr, nc, er, ec;
	cr=point[0].first, cc=point[0].second;
	er=point[1].first, ec=point[1].second;
	Q.push({{cr, cc}, 0});
	res[cr][cc]=0;
	while(Q.size()){
		cr=Q.front().r, cc=Q.front().c, cs=Q.front().s;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=cr, nc=cc;
			while(1){
				nr+=dr[i], nc+=dc[i];
				if(!chk(nr, nc) || wall[nr][nc])	break;
				if(res[nr][nc]==-1){
					res[nr][nc]=cs;
					Q.push({{nr, nc}, cs+1});
				}
			}
		}
	}
	cout<<res[er][ec]<<"\n";
	return 0;
}
