#include<iostream>
using namespace std;
int N, M, inp[40][40];
int f(int x){
	return x<0 ? N-x-1:x-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		inp[f(-a)][f(b)]=1;
		inp[f(-b)][f(a)]=1;
	}
	for(int k=0;k<2*N;++k){
		for(int i=0;i<2*N;++i){
			for(int j=0;j<2*N;++j){
				if(inp[i][k] && inp[k][j])
					inp[i][j]=1;
			}
		}
	}
	bool res=true;
	for(int i=0;i<N && res;++i){
		if(inp[i+N][i] && inp[i][i+N])	res=false;
	}
	cout<<res<<"\n";
	return 0;
}
