#include<iostream>
#include<vector>
using namespace std;
typedef vector<pair<int, int> > vp;
int arr[10], ans;
int board[4][22]={{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24,
	26, 28, 30, 32, 34, 36, 38, 40, 0},
	{10, 13, 16, 19, 25, 30, 35, 40, 0}, 
	{20, 22, 24, 25, 30, 35, 40, 0}, 
	{30, 28, 27, 26, 25, 30, 35, 40, 0}};
bool visit[4][22];
void sol(int cnt, int sum, vp& h){
	if(cnt>9){
		if(sum>ans)	ans=sum;
		if(sum==218)
			sum=0;
		return;
	}
	vp next(4);
	next=h;
	for(int i=0;i<4;++i){
		int r=h[i].first, c=h[i].second+arr[cnt];
		if(r==-1)	continue;
		if(c>20 || board[r][c]==0){
			visit[r][c-arr[cnt]]=false;
			next[i]={-1, -1};
			sol(cnt+1, sum, next);
			next[i]=h[i];
			visit[r][c-arr[cnt]]=true;
		}
		else{
			if(r==0){
				int nr=r, nc=c;
				if(c==5){
					nr=1, nc=0;
				}
				else if(c==10){
					nr=2, nc=0;
				}
				else if(c==15){
					nr=3, nc=0;
				}
				if(visit[nr][nc])	continue;
				next[i]={nr, nc};
				visit[r][c-arr[cnt]]=false;
				visit[nr][nc]=true;
				sol(cnt+1, sum+board[nr][nc], next);
				next[i]=h[i];
				visit[nr][nc]=false;
				visit[r][c-arr[cnt]]=true;
			}
			else{
				int nr=r, nc=c;
				if(board[r][c]==25)
					nr=1, nc=4;
				else if(board[r][c]==30 && r>0 && c>0)
					nr=1, nc=5;
				else if(board[r][c]==35)
					nr=1, nc=6;
				else if(board[r][c]==40)
					nr=0, nc=20;
				if(visit[nr][nc])	continue;
				else{
					next[i]={nr, nc};
					visit[r][c-arr[cnt]]=false;
					visit[nr][nc]=true;
					sol(cnt+1, sum+board[nr][nc], next);
					next[i]=h[i];
					visit[nr][nc]=false;
					visit[r][c-arr[cnt]]=true;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<10;++i)	cin>>arr[i];
	vp start(4, {0, 0});
	sol(0, 0, start);
	cout<<ans<<"\n";
	return 0;
}
