#include<stdio.h>
int main(){
	char grid[101][101]={0, }, dy[4]={0, -1, 0, 1}, dx[4]={1, 0, -1, 0};
	int N, x, y, d, g, ans=0;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d %d %d", &x, &y, &d, &g);
		grid[y][x]=1;
		x+=dx[d];y+=dy[d];
		grid[y][x]=1;
		char drg[1024]={d};
		for(int t=0, c=1;t<g;++t, c<<=1){
			for(int j=0;j<c;++j){
				d=drg[c+j]=(drg[c-j-1]+1)%4;
				x+=dx[d];y+=dy[d];
				grid[y][x]=1;
			}
		}
	}
	for(int i=0;i<100;++i){
		for(int j=0;j<100;++j){
			if(grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1])
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
