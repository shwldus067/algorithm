#include<iostream>
#include<cmath>
using namespace std;
int N, M, S[20][20], ans=2e9, all, c[20], r[20];
bool chk[20];
void sol(int idx, int cnt, int sum){
	if(cnt==M){
		if(ans>abs(sum)){
			ans=abs(sum);
		}
		return;
	}
	if(idx==N)	return;
	sol(idx+1, cnt+1, sum-r[idx]-c[idx]);
	sol(idx+1, cnt, sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		cin>>S[i][j];
		all+=S[i][j];
		r[i]+=S[i][j];
		c[j]+=S[i][j];
	}
	M=N/2;
	sol(1, 1, all-r[0]-c[0]);
	cout<<ans<<"\n";
	return 0;
}
