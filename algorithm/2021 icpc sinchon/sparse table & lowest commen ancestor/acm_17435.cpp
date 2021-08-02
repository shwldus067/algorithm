#include<iostream>
using namespace std;
int f[200001][19];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M, Q, n, x;
	cin>>M;
	for(int i=1;i<=M;++i)	cin>>f[i][0];
	for(int k=1;k<19;++k)for(int i=1;i<=M;++i)
		f[i][k]=f[f[i][k-1]][k-1];
	cin>>Q;
	while(Q--){
		cin>>n>>x;
		for(int i=0;i<19;++i){
			if(n&(1<<i))	x=f[x][i];
		}
		cout<<x<<"\n";
	}
	return 0;
}
