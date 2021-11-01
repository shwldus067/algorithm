#include<iostream>
#include<vector>
using namespace std;
int N, ans, M;
vector<int> bishop[20];
bool chk[20];
void sol(int k, int n){
	if(k==M){
		ans=max(ans, n);
		return;
	}
	if(M-k<=ans-n)	return;
	for(int b:bishop[k]){
		if(chk[b])	continue;
		chk[b]=1;
		sol(k+1, n+1);
		chk[b]=0;
	}
	sol(k+1, n);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		cin>>t;
		if(t){
			int x=i-j+N, y=i+j;
			bishop[y].push_back(x);
		}
	}
	M=N+N-1;
	sol(0, 0);
	cout<<ans<<"\n";
	return 0;
}
