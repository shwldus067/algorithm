#include<iostream>
#include<algorithm>
using namespace std;
int N, K, T[10][10], M;
int S[10];
int sol(){
	int ret=0;
	for(int i=1;i<N;++i){
		ret+=T[S[i-1]][S[i]];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>T[i][j];
	for(int k=0;k<N;++k)for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		if(T[i][j]>T[i][k]+T[k][j]){
			T[i][j]=T[i][k]+T[k][j];
		}
	}
	for(int i=0;i<N;++i)	S[i]=i;
	int ans=1e6;
	do{
		if(S[0]==K){
			ans=min(ans, sol());
		}
	}while(next_permutation(S, S+N));
	cout<<ans<<"\n";
	return 0;
}
