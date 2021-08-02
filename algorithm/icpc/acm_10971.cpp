#include<iostream>
using namespace std;
int N, arr[10][10], ans=1e8, st;
bool chk[10];
void sol(int n, int k, int w){
	if(w>=ans)	return;
	if(n==N){
		if(!arr[k][st])	return;
		w+=arr[k][st];
		if(ans>w)	ans=w;
		return;
	}
	for(int i=0;i<N;++i){
		if(arr[k][i] && !chk[i]){
			chk[i]=1;
			sol(n+1, i, w+arr[k][i]);
			chk[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>arr[i][j];
	chk[0]=1;
	sol(1, 0, 0);
	cout<<ans<<"\n";
	return 0;
}
