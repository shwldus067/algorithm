#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, M, K, A[2000], B[2000], d[2000][2000], lis[2000];
vector<int> adj[2000];
int sol(int a, int b){
	if(a==N || b==M)	return 0;
	int &ret=d[a][b];
	if(ret!=-1)	return ret;
	ret=sol(a+1, b);
	auto iter=lower_bound(adj[a].begin(), adj[a].end(), b);
	if(iter!=adj[a].end())	ret=max(sol(a+1, (*iter)+1)+1, ret);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int t;
	for(int i=0;i<N;++i){
		cin>>t;
		A[t-1]=i;
	}
	for(int i=0;i<M;++i){
		cin>>t;
		B[t-1]=i;
	}
	cin>>K;
	for(int i=0;i<K;++i){
		int a, b;
		cin>>a>>b;
		adj[A[a-1]].push_back(B[b-1]);
	}
	for(int i=0;i<N;++i)for(int j=0;j<M;++j)	d[i][j]=-1;
	for(int i=0;i<N;++i)	sort(adj[i].begin(), adj[i].end());
	cout<<K-sol(0, 0)<<"\n";
}
