#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	N/=2;
	int ans[N+1]={1, 1, };
	for(int i=2;i<=N;++i){
		for(int j=0;j<i/2;++j){
			ans[i]=(ans[i]+2ll*ans[j]*ans[i-j-1])%987654321;
		}
		if(i%2)	ans[i]=(ans[i]+1ll*ans[i/2]*ans[i/2])%987654321;
	}
	cout<<ans[N]<<"\n";
	return 0;
}
