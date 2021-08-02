#include<stdio.h>
int N;
int pow[11]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int dy[4]={0, -1, 0, 1}, dx[4]={1, 0, -1, 0};
int drg[1025];
bool grid[101][101];
int main(){
	int idx=0;
	for(int i=1;i<11;++i){
		for(int j=idx;~j;--j){
			drg[++idx]=drg[j]>2 ? 0:drg[j]+1;
		}
	}
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		grid[y][x]=1;
		for(int i=0;i<pow[g];++i){
			int dd=drg[i]+d;
			dd=dd<4?dd:dd-4;
			x=x+dx[dd]; y=y+dy[dd];
			grid[y][x]=1;
		}
	}
	int ans=0;
	for(int i=0;i<100;++i){
		for(int j=0;j<100;++j){
			if(grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1])
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
