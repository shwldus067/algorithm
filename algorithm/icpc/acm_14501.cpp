#include<iostream>
using namespace std;
int N, T[15], P[15], ans;
void sol(int idx, int last, int sum){
	if(idx==N){
		if(ans<sum)	ans=sum;
		return;
	}
	if(last<idx && idx+T[idx]-1<N)
		sol(idx+1, idx+T[idx]-1, sum+P[idx]);
	sol(idx+1, last, sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>T[i]>>P[i];
	}
	sol(0, -1, 0);
	cout<<ans<<"\n";
	return 0;
}
