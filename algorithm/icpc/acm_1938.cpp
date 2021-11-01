#include<iostream>
#include<queue>
using namespace std;
struct node{
	int r, c, d;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, r, c, d, ans=0, cnt=0;
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	char arr[52][53]={0, };
	bool visit[52][52][2]={0, };
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>arr[i]+1;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		int x=0, y=0;
		for(int k=-1;k<2;++k)if(arr[i+k][j]=='B')	++x;
		for(int k=-1;k<2;++k)if(arr[i][j+k]=='B')	++y;
		if(x==3 || y==3){
			r=i, c=j;
			if(x==3)	d=1;	//vertical
			else	d=0;	//horizontal
			break;
		}
	}
	queue<node> Q;
	visit[r][c][d]=1;
	Q.push({r, c, d});
	while(int size=Q.size()){
		while(size--){
			struct node str=Q.front();Q.pop();
			int tmp=0, chk=1;
			if(str.d){
				for(int i=-1;i<2;++i)if(arr[str.r+i][str.c]!='E')	chk=0;
			}else{
				for(int i=-1;i<2;++i)if(arr[str.r][str.c+i]!='E')	chk=0;
			}
			if(chk){
				cout<<ans<<"\n";
				return 0;
			}
			for(int k=0;k<4;++k){
				int nr=str.r+dr[k], nc=str.c+dc[k];
				chk=1;
				if(visit[nr][nc][str.d])	continue;
				if(str.d){
					for(int i=-1;i<2;++i)
						if(arr[nr+i][nc]=='1' || arr[nr+i][nc]==0)	chk=0;
				}else{
					for(int i=-1;i<2;++i)
						if(arr[nr][nc+i]=='1' || arr[nr][nc+i]==0)	chk=0;
				}
				if(chk){
					visit[nr][nc][str.d]=1;
					Q.push({nr, nc, str.d});
				}
			}
			if(visit[str.r][str.c][str.d^1])	continue;
			if(str.r<2 || str.r>=N || str.c<2 || str.c>=N)	continue;
			chk=1;
			for(int i=-1;i<2;++i)for(int j=-1;j<2;++j){
				if(arr[str.r+i][str.c+j]=='1'){
					chk=0;break;
				}
			}
			if(chk){
				visit[str.r][str.c][str.d^1]=1;
				Q.push({str.r, str.c, str.d^1});
			}
		}
		++ans;
	}
	cout<<"0\n";
	return 0;
}
