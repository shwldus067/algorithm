#include<iostream>
#include<vector>
using namespace std;
bool chk[1001][1001], visit[1001];
int N, M, ans[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		chk[a][b]=1;
	}
	for(int i=1;i<=N;++i){
		ans[i]=1;
		for(int j=1;j<i;++j){
			if(chk[j][i]){
				ans[i]=max(ans[i], ans[j]+1);
			}
		}
	}
	for(int i=1;i<=N;++i)
		cout<<ans[i]<<" ";
	return 0;
}
