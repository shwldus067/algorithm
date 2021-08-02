#include<iostream>
using namespace std;
int N, L, R, X, A[15], ans;
void sol(int x, int m, int M, int sum){
	if(L<=sum && sum<=R && M-m>=X)	ans++;
	for(int i=x;i<N;++i){
		if(sum+A[i]>R)	continue;
		sol(i+1, min(m, A[i]), max(M, A[i]), sum+A[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>R>>X;
	for(int i=0;i<N;++i)	cin>>A[i];
	sol(0, 1e6, 1, 0);
	cout<<ans<<"\n";
	return 0;
}
