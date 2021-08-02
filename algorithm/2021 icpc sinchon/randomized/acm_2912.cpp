#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, M, C, arr[300001], seg[1<<20];
pii q[300001];
void update(int x, int l, int r){
	if(l==r){
		seg[x]=arr[l];return;
	}
	int m=(l+r)/2;
	update(2*x, l, m);
	update(2*x+1, m+1, r);
	int n=seg[2*x];
	int cnt=upper_bound(q, q+N, make_pair(n, r))-lower_bound(q, q+N, make_pair(n, l));
	if(cnt>(r-l+1)/2)	seg[x]=n;
	else{
		n=seg[2*x+1];
		cnt=upper_bound(q, q+N, make_pair(n, r))-lower_bound(q, q+N, make_pair(n, l));
		if(cnt>(r-l+1)/2)	seg[x]=n;
		else	seg[x]=0;
	}
}
int query(int a, int b, int x, int l, int r){
	if(a>r || b<l)	return 0;
	if(a<=l && r<=b){
		int cnt=upper_bound(q, q+N, make_pair(seg[x], b))-lower_bound(q, q+N, make_pair(seg[x], a));
		if(cnt>(b-a+1)/2)	return seg[x];
		else return 0;
	}
	int m=(l+r)/2;
	int ret=query(a, b, 2*x, l, m);
	if(ret)	return ret;
	ret=query(a, b, 2*x+1, m+1, r);
	if(ret)	return ret;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>C;
	for(int i=0;i<N;++i){
		cin>>arr[i+1];
		q[i]={arr[i+1], i+1};
	}
	sort(q, q+N);
	update(1, 1, N);
	cin>>M;
	int a, b;
	while(M--){
		cin>>a>>b;
		int ans=query(a, b, 1, 1, N);
		if(ans)	cout<<"yes "<<ans<<'\n';
		else	cout<<"no\n";
	}
	return 0;
}
