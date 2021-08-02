#include<iostream>
using namespace std;
int T, N;
int arr[1000], d[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i)	cin>>arr[i];
		int t=N&1;
		for(int k=0;k<N;++k){
			for(int s=0;s<N-k;++s){
				int e=s+k;
				if(t==1){
					d[s][e]=max(d[s+1][e]+arr[s], d[s][e-1]+arr[e]);
				}
				else{
					d[s][e]=min(d[s+1][e], d[s][e-1]);
				}
			}
			t^=1;
		}
		cout<<d[0][N-1]<<"\n";
	}
	return 0;
}
