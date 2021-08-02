#include<iostream>
using namespace std;
void sol(){
	int N, M, rnk[501], ans[501];
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		rnk[t]=ans[t]=i+1;
	}
	cin>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		if(rnk[a]>rnk[b])	--ans[a], ++ans[b];
		else	++ans[a], --ans[b];
	}
	int order[501]={0, };
	for(int i=1;i<=N;++i){
		int t=ans[i];
		if(order[t]){
			cout<<"IMPOSSIBLE\n";
			return;
		}
		order[t]=i;
	}
	for(int i=1;i<=N;++i)	cout<<order[i]<<" ";
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		sol();
	}
	return 0;
}
