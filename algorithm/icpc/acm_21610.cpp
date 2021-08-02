#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int main(){
	int N, M, A[50][50], d, s, pcnt=4;
	int dr[8]={0, -1, -1, -1, 0, 1, 1, 1};
	int dc[8]={-1, -1, 0, 1, 1, 1, 0, -1};
	bool chk[50][50]={0, };
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &A[i][j]);
	pii points[2500];
	points[0]={N-1, 0};points[1]={N-1, 1};
	points[2]={N-2, 0};points[3]={N-2, 1};
	while(M--){
		scanf("%d %d", &d, &s);
		--d;
		for(int i=0;i<pcnt;++i){
			int r=points[i].first, c=points[i].second;
			r=(r+s*dr[d])%N;c=(c+s*dc[d])%N;
			if(r<0)	r+=N;
			if(c<0)	c+=N;
			points[i]={r, c};
			chk[r][c]=1;
			A[r][c]++;
		}
		for(int i=0;i<pcnt;++i){
			int r=points[i].first, c=points[i].second;
			for(int j=1;j<8;j+=2){
				int nr=r+dr[j], nc=c+dc[j];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(A[nr][nc]){
					A[r][c]++;
				}
			}
		}
		pcnt=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(chk[i][j]){
					chk[i][j]=0;
				}else if(A[i][j]>=2){
					points[pcnt++]={i, j};
					A[i][j]-=2;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	ans+=A[i][j];
	printf("%d\n", ans);
	return 0;
}
