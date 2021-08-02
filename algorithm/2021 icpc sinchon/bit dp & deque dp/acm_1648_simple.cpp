#include<iostream>
using namespace std;
const int mod=9901;
int d[15][1<<14];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, L;
	cin>>N>>M;
	K=1<<M;L=N*M;
	d[0][K-1]=1;
	// 한 줄 씩 채움 
	for(int i=1;i<=N;++i){
		// i번째 줄까지 세로 도미노로 채움 
		// 윗 줄이 채워져 있으면 세로를 둘 수 없고 
		// 윗 줄이 비었으면 아랫 줄에서 채워야 모든 칸을 채울 수 있음 
		for(int j=0;j<K;++j)	d[i][j]=d[i-1][(~j)&(K-1)];
		// 가로 도미노로 채움 
		for(int j=3;j<K;j<<=1){
			for(int k=0;k<K;++k){
				if(k&j)	continue;
				// k상태에서 가로칸을 하나 추가함 
				d[i][k|j]=(d[i][k|j]+d[i][k])%mod;
			}
		}
	}
	cout<<d[N][K-1]<<"\n";
	return 0;
}
