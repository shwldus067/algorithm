#include<iostream>
using namespace std;
int N, M;
char ans[18];
void sol(int n, int k){
	if(n==M){
		cout<<ans<<"\n";
		return;
	}
	for(int i=k;i<=N;++i){
		ans[n]=i+'0';
		ans[n+1]=' ';
		sol(n+2, i);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	M+=M;
	sol(0, 1);
	return 0;
}
