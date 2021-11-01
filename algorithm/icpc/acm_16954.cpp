#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r, c, size, cnt=0;
	int dr[9]={-1, -1, -1, 0, 1, 1, 1, 0, 0};
	int dc[9]={-1, 0, 1, 1, 1, 0, -1, -1, 0};
	char arr[20][9]={0, };
	bool visit[20][9]={0, };
	for(int i=0;i<8;++i)	cin>>arr[7-i];
	queue<pii> Q;
	Q.push({0, 0});
	visit[0][0]=1;
	while(size=Q.size()){
		while(size--){
			r=Q.front().first, c=Q.front().second;
			Q.pop();
			if(arr[r][c]=='#')	continue;
			for(int i=0;i<9;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nc<0 || nc>7 || nr<cnt || nr>cnt+7)	continue;
				if(arr[nr][nc]=='#')	continue;
				if(visit[nr+1][nc])	continue;
				if(nr>7){
					cout<<"1\n";
					return 0;
				}
				Q.push({nr+1, nc});
				visit[nr+1][nc]=1;
			}
		}
		cnt++;
	}
	cout<<"0\n";
	return 0;
}
