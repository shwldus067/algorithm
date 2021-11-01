#include<iostream>
using namespace std;
typedef struct str{
	int r, c, k;
}str;
str Q[1240000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, W, H, size, cnt=0, arr[200][200];
	int hr[8]={-1, -2, -2, -1, 1, 2, 2, 1};
	int hc[8]={-2, -1, 1, 2, 2, 1, -1, -2};
	int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
	bool visit[31][200][200]={0, };
	cin>>K>>W>>H;
	for(int i=0;i<H;++i)for(int j=0;j<W;++j)	cin>>arr[i][j];
	int front=0, rear=0;
	Q[rear++]={0, 0, 0};
	while(size=rear-front){
		while(size--){
			int r=Q[front].r, c=Q[front].c, k=Q[front++].k;
			if(r==H-1 && c==W-1){
				cout<<cnt<<"\n";
				return 0;
			}
			for(int i=0;i<4;++i){
				int nr=r+dr[i], nc=c+dc[i];
				if(nr<0 || nr>=H || nc<0 || nc>=W)	continue;
				if(arr[nr][nc])	continue;
				if(visit[k][nr][nc])	continue;
				visit[k][nr][nc]=1;
				Q[rear++]={nr, nc, k};
			}
			if(k==K)	continue;
			for(int i=0;i<8;++i){
				int nr=r+hr[i], nc=c+hc[i];
				if(nr<0 || nr>=H || nc<0 || nc>=W)	continue;
				if(arr[nr][nc])	continue;
				if(visit[k+1][nr][nc])	continue;
				visit[k+1][nr][nc]=1;
				Q[rear++]={nr, nc, k+1};
			}
		}
		cnt++;
	}
	cout<<"-1\n";
	return 0;
}
