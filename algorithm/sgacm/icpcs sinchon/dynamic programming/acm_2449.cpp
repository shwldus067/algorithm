#include<iostream>
using namespace std;
const int inf=1<<30;
int N, K, d[200][200], arr[200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		for(int j=i-1;j>=0;--j){
			d[j][i]=inf;
			for(int k=j;k<i;++k){
				d[j][i]=min(d[j][i], d[j][k]+d[k+1][i]+(arr[j]!=arr[k+1]));
			}
		}
	}
	cout<<d[0][N-1]<<"\n";
	return 0;
}
