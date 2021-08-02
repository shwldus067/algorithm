#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
pii A[100000];
int N, ans=2e9, sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i].first>>A[i].second;
	}
	sort(A, A+N);
	for(int i=0, r, l=-1;i<N;++i){
		int s=A[i].first, e=A[i].second;
		sum+=max(e-max(s, l), 0);
		r=(i==N-1 ? e:min(e, A[i+1].first));
		l=max(l, s);
		ans=min(ans, max(r-l, 0));
		l=max(l, e);
	}
	cout<<sum-ans<<"\n";
	return 0;
}
