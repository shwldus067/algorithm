#include<iostream>
#include<queue>
using namespace std;
struct str{
	int r, c, num, h;
	str(){
	}
	str(int r, int c, int num, int h):r(r), c(c), num(num), h(h){
	}
};
int N, dist, ans;
int kr[8]={2, 1, -1, -2, -2, -1, 1, 2};
int kc[8]={1, 2, 2, 1, -1, -2, -2, -1};
int br[4]={1, 1, -1, -1};
int bc[4]={1, -1, -1, 1};
int rr[4]={1, -1, 0, 0};
int rc[4]={0, 0, 1, -1};
int arr[10][10];
int dp[10][10][101][3];
queue<str> Q;
bool chk(int nr, int nc){
	return 0<=nr && nr<N && 0<=nc && nc<N;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill(&dp[0][0][0][0], &dp[9][9][100][3], -1);
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				for(int k=0;k<3;k++){
					dp[i][j][1][k]=0;
					Q.push(str(i, j, 1, k));
				}
			}
		}
	dist=N*N;
	ans=-1;
	str cur;
	int r, c, num, h;
	while(Q.size()){
		cur=Q.front();
		Q.pop();
		r=cur.r, c=cur.c, num=cur.num, h=cur.h;
		if(num==dist){
			if(ans==-1 || ans>dp[r][c][num][h]){
				ans=dp[r][c][num][h];
			}
		}
		for(int i=0;i<3;i++){
			if(h==i)	continue;
			if(dp[r][c][num][i]==-1){
				dp[r][c][num][i]=dp[r][c][num][h]+1;
				Q.push(str(r, c, num, i));
			}
		}
		//bishop
		if(h==0){
			for(int i=0;i<4;i++){
				int nr=r+br[i], nc=c+bc[i];
				while(chk(nr, nc)){
					int next=num;
					if(arr[nr][nc]==next+1){
						next++;
					}
					if(dp[nr][nc][next][h]==-1){
						dp[nr][nc][next][h]=dp[r][c][num][h]+1;
						Q.push(str(nr, nc, next, h));
					}
					nr+=br[i], nc+=bc[i];
				}
			}
		}
		//rook
		else if(h==1){
			for(int i=0;i<4;i++){
				int nr=r+rr[i], nc=c+rc[i];
				while(chk(nr, nc)){
					int next=num;
					if(arr[nr][nc]==num+1){
						next++;
					}
					if(dp[nr][nc][next][h]==-1){
						dp[nr][nc][next][h]=dp[r][c][num][h]+1;
						Q.push(str(nr, nc, next, h));
					}
					nr+=rr[i], nc+=rc[i];
				}
			}
		}
		//knight
		else{
			for(int i=0;i<8;i++){
				int nr=r+kr[i], nc=c+kc[i];
				if(chk(nr, nc)){
					int next=num;
					if(arr[nr][nc]==num+1){
						next++;
					}
					if(dp[nr][nc][next][h]==-1){
						dp[nr][nc][next][h]=dp[r][c][num][h]+1;
						Q.push(str(nr, nc, next, h));
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
