#include<iostream>
#include<algorithm>
using namespace std;
int A[250001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, Q, x, y;
	cin>>N>>Q;
	A[0]=0;
	for(int i=1;i<=N;++i)	cin>>A[i], A[i]=-A[i];
	while(Q--){
		cin>>x>>y;
		int ans=0;
		if(-A[y]>=x)
			ans+=-A[y]-x+(upper_bound(A, A+N+1, -x)-A)-y;
		cout<<ans<<"\n";
	}
	return 0;
}
