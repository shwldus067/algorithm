#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int arr[5][5];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, -1, 0, 1};
vector<int> ans;
void dfs(int r, int c, int k, int n){
	if(n==5){
		ans.push_back(k);
		return;
	}
	for(int i=0;i<4;++i){
		int nr=r+dr[i], nc=c+dc[i];
		if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
		dfs(nr, nc, k*10+arr[nr][nc], n+1);
	}
}
int main(){
	for(int i=0;i<5;++i)for(int j=0;j<5;++j)	scanf("%d", &arr[i][j]);
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			dfs(i, j, arr[i][j],0);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", ans.size());
	return 0;
}
