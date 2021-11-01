#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, a, b;
	int scale[101][101]={0, };
	cin>>N>>M;
	while(M--){
		cin>>a>>b;
		scale[a][b]=1;
		scale[b][a]=2;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			for(int k=1;k<=N;++k){
				if(scale[j][i] && scale[j][i]==scale[i][k]){
					scale[j][k]=scale[j][i];
					scale[k][j]=scale[j][k]==1?2:1;
				}
			}
		}
	}
	for(int i=1;i<=N;++i){
		int cnt=0;
		for(int j=1;j<=N;++j){
			if(i==j)	continue;
			if(scale[i][j]==0)	++cnt;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
