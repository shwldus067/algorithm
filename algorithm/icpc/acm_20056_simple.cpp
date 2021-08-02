#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, M, K;
int dr[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8]={0, 1, 1, 1, 0, -1, -1, -1};
struct fb{
	int m, s, d;
}FB[2][50][50];
struct str{
	int r, c, d;
};
int cnt[50][50];
str qu[2][10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	int r, c, m, s, d;
	int e=0;
	while(M--){
		cin>>r>>c>>m>>s>>d;
		FB[0][r-1][c-1]={m, s, d};
		qu[0][e++]={r-1, c-1, d};
	}
	int t=0, p=N*(1000/N+1);
	while(K--){
		for(int i=0;i<e;++i){
			int r=qu[t][i].r, c=qu[t][i].c;
			int d=qu[t][i].d, s=FB[t][r][c].s;
			int nr=(r+dr[d]*s+p)%N, nc=(c+dc[d]*s+p)%N;
			fb &tp=FB[t^1][nr][nc];
			if(cnt[nr][nc]){
				tp.m+=FB[t][r][c].m;
				tp.s+=s;
				if(tp.d>=0 && (tp.d&1)!=(d&1))	tp.d=-1;
			}
			else{
				tp={FB[t][r][c].m, s, d};
			}
			cnt[nr][nc]++;
			qu[t][i].r=nr, qu[t][i].c=nc;
		}
		int ne=0;
		for(int i=0;i<e;++i){
			int r=qu[t][i].r, c=qu[t][i].c;
			if(cnt[r][c]==0)	continue;
			if(cnt[r][c]==1){
				qu[t^1][ne++]={r, c, qu[t][i].d};
			}
			else if(cnt[r][c]>1){
				fb &div=FB[t^1][r][c];
				div.m/=5;
				if(!div.m){
					cnt[r][c]=0;continue;
				}
				div.s/=cnt[r][c];
				int d=div.d;
				if(d<0)	d=1;
				else	d=0;
				for(int k=0;k<4;++k, d+=2){
					qu[t^1][ne++]={r, c, d};
				}
			}
			cnt[r][c]=0;
		}
		t^=1;
		e=ne;
	}
	int ans=0;
	for(int i=0;i<e;++i){
		ans+=FB[t][qu[t][i].r][qu[t][i].c].m;
	}
	cout<<ans<<"\n";
	return 0;
}
