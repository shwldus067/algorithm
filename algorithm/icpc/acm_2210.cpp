#include<cstdio>
int ans=0;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
bool chk[10][10][10][10][10][10];
int num[6], arr[5][5];
void dfs(int r, int c, int k, int n){
	if(n==5){
		bool &ret=chk[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]];
		if(ret)	return;
		ret=1;
		ans++;
		return;
	}
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
		num[n+1]=arr[nr][nc];
		dfs(nr, nc, arr[nr][nc], n+1);
	}
}
int main(){
	for(int i=0;i<5;++i)for(int j=0;j<5;++j)	scanf("%d", &arr[i][j]);
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			num[0]=arr[i][j];
			dfs(i, j, arr[i][j],0);
		}
	}
	printf("%d\n", ans);
	return 0;
}
