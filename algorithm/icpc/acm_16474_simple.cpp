#include<iostream>
#include<algorithm>
using namespace std;
int N, M, K, A[2001], B[2001], d[2001][2001];
bool adj[2001][2001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int t;
	++N, ++M;
	for(int i=1;i<N;++i){
		cin>>t;
		A[t]=i;
	}
	for(int i=1;i<M;++i){
		cin>>t;
		B[t]=i;
	}
	cin>>K;
	for(int i=0;i<K;++i){
		int a, b;
		cin>>a>>b;
		adj[A[a]][B[b]]=true;
	}
	for(int i=1;i<N;++i){
		for(int j=1;j<M;++j){
			d[i][j]=max(max(d[i-1][j-1]+adj[i][j], d[i-1][j]), d[i][j-1]);
		}
	}
	cout<<K-d[N-1][M-1]<<"\n";
	return 0;
}
