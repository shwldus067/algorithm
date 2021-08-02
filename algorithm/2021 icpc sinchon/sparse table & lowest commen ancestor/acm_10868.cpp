#include<iostream>
using namespace std;
int d[100000][17];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, a, b, c, t=1, K=0, f;
	fill(&d[0][0], &d[99999][17], 2e9);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>d[i][0];
	while(t*2<=N)	t*=2, ++K;
	++K;
	for(int k=1;k<K;++k)for(int i=0;i<N-(1<<k)+1;++i)
		d[i][k]=min(d[i][k-1], d[i+(1<<k-1)][k-1]);
	while(M--){
		cin>>a>>b;
		--a;
		c=b-a;t=1;f=0;
		while(t*2<=c)	t*=2, ++f;
		int ans=min(d[a][f], d[b-t][f]);
		cout<<ans<<"\n";
	}
	return 0;
}
