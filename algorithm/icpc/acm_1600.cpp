#include<iostream>
#include<queue>
using namespace std;
#define inf 1000000
typedef struct str{
	int r, c, k;
}str;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, W, H, size, cnt=0, arr[200][200];
	int dr[12]={-1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 1, 0};	//0~7:horse
	int dc[12]={-2, -1, 1, 2, 2, 1, -1, -2, 0, 1, 0, -1};
	bool visit[31][200][200]={0, };
	cin>>K>>W>>H;
	for(int i=0;i<H;++i)for(int j=0;j<W;++j)	cin>>arr[i][j];
	queue<str> Q;
	Q.push({0, 0, 0});
	while(size=Q.size()){
		while(size--){
			int r=Q.front().r, c=Q.front().c, k=Q.front().k;
			Q.pop();
			if(r==H-1 && c==W-1){
				cout<<cnt<<"\n";
				return 0;
			}
			for(int i=0;i<12;++i){
				int nr=r+dr[i], nc=c+dc[i], nk=k+(i<8?1:0);
				if(nr<0 || nr>=H || nc<0 || nc>=W || nk>K)	continue;
				if(arr[nr][nc])	continue;
				if(visit[nk][nr][nc])	continue;
				visit[nk][nr][nc]=1;
				Q.push({nr, nc, nk});
			}
		}
		cnt++;
	}
	cout<<"-1\n";
	return 0;
}
