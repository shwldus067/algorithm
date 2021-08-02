#include<iostream>
using namespace std;
int N, K, w[101], v[101], d[101][100001], tmp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;++i)	cin>>w[i]>>v[i];
	for(int i=1;i<=N;++i){
		for(int j=1;j<=K;j++){
			if(w[i]<=j){
				if((tmp=v[i]+d[i-1][j-w[i]])>d[i-1][j])
					d[i][j]=tmp;
				else
					d[i][j]=d[i-1][j];
			}
			else	d[i][j]=d[i-1][j];
		}
	}
	cout<<d[N][K]<<"\n";
	return 0;
}
