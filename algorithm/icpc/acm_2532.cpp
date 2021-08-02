#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N;
pii A[500000];
bool cmp(const pii &a, const pii &b){
	if(a.first!=b.first)	return a.first<b.first;
	return a.second>b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t>>A[i].first>>A[i].second;
	}
	sort(A, A+N, cmp);
	int res[N]={-A[0].second, }, cnt=0;
	for(int i=1;i<N;++i){
		if(A[i]==A[i-1])	continue;
		if(res[cnt]<=-A[i].second){
			res[++cnt]=-A[i].second;
		}
		else{
			int *it=upper_bound(res, res+cnt+1, -A[i].second);
			*it=-A[i].second;
		}
	}
	cout<<cnt+1<<"\n";
	return 0;
}
