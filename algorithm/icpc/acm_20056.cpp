#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, M, K;
int dr[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8]={0, 1, 1, 1, 0, -1, -1, -1};
struct fb{
	int m, s, d;
}FB[2][50][50][4];
int cnt[50][50];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	int r, c, m, s, d;
	for(int i=0;i<M;++i){
		cin>>r>>c>>m>>s>>d;
		FB[0][r-1][c-1][0]={m, s, d};
	}
	int t=0, p=N*(1000/N+1);
	while(K--){
		t^=1;
		for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			cnt[i][j]=0;
			for(int k=0;k<4;++k)	FB[t][i][j][k].m=0;
		}
		t^=1;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				for(int k=0;k<4 && FB[t][i][j][k].m;++k){
					int m=FB[t][i][j][k].m;
					int s=FB[t][i][j][k].s, d=FB[t][i][j][k].d;
					int r=(i+dr[d]*s+p)%N, c=(j+dc[d]*s+p)%N;
					fb &tp=FB[t^1][r][c][0];
					if(cnt[r][c]){
						tp.m+=m;
						tp.s+=s;
						if(tp.d>=0 && (tp.d&1)!=(d&1))	tp.d=-1;
					}
					else{
						tp.m=m;
						tp.s=s;
						tp.d=d;
					}
					cnt[r][c]++;
				}
			}
		}
		t^=1;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(cnt[i][j]>1){
					fb &div=FB[t][i][j][0];
					int m=div.m/5;
					if(!m){
						div.m=0;
						continue;
					}
					int s=div.s/cnt[i][j], d=div.d;
					if(d<0)	d=1;
					else	d=0;
					for(int k=0;k<4;++k, d+=2){
						FB[t][i][j][k]={m, s, d};
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<4 && FB[t][i][j][k].m;++k){
				ans+=FB[t][i][j][k].m;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
