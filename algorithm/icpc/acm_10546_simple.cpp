#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	char par[21], ans[21]={0, };
	cin>>N;
	N=N+N-1;
	while(N--){
		cin>>par;
		for(int i=0;par[i];++i){
			ans[i]^=par[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
