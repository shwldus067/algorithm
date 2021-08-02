#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define x first
#define y second
int tc, h, w, res[3][102][102], ans;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char arr[102][102];
vector<pair<int, int> > v;
bool chk(int nr, int nc){
	return nr>=0 && nr<=h+1 && nc>=0 && nc<=w+1;
}
void bfs(int idx){
	int cr, cc, nr, nc;
	deque<pair<int, int> > dq;
	cr=v[idx].x, cc=v[idx].y;
	dq.push_front({cr, cc});
	res[idx][cr][cc]=1;
	while(dq.size()){
		cr=dq.front().x, cc=dq.front().y;
		dq.pop_front();
		for(int i=0;i<4;i++){
			nr=cr+dr[i], nc=cc+dc[i];
			if(!chk(nr, nc) || res[idx][nr][nc] || arr[nr][nc]=='*')
				continue;
			if(arr[nr][nc]=='#'){
				res[idx][nr][nc]=res[idx][cr][cc]+1;
				dq.push_back({nr, nc});
			}
			else{
				res[idx][nr][nc]=res[idx][cr][cc];
				dq.push_front({nr, nc});
			}
			
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	while(tc--){
		v.clear();
		ans=10000;
		cin>>h>>w;
		for(int i=1;i<=h;i++){
			arr[i][0]='.';
			for(int j=1;j<=w;j++){
				cin>>arr[i][j];
				if(arr[i][j]=='$')
					v.push_back({i, j});
			}
			arr[i][w+1]='.';
		}
		for(int j=0;j<=w+1;j++){
			arr[0][j]=arr[h+1][j]='.';
		}
		v.push_back({0, 0});
		bfs(0);
		bfs(1);
		bfs(2);
		int sum=0;
		for(int i=0;i<=h+1;i++){
			for(int j=0;j<=w+1;j++){
				if(arr[i][j]=='*')	continue;
				else if(arr[i][j]=='#'){
					sum=res[0][i][j]+res[1][i][j]+res[2][i][j]-5;
					if(sum<0)	continue;
					ans=min(ans, sum);
				}
				else{
					sum=res[0][i][j]+res[1][i][j]+res[2][i][j]-3;
					if(sum<0)	continue;
					ans=min(ans, sum);
				}
				res[0][i][j]=res[1][i][j]=res[2][i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
