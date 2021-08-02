#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<pair<int, int> > vii;
typedef vector<int> vi;
typedef pair<int, int> pii;
pii init(vii& t, vi& a, int nx, int s, int e){
	if(s==e){
		t[nx].first=t[nx].second=a[s];
		return t[nx];
	}
	pii f_p=init(t, a, nx<<1, s, (s+e)/2);
	pii s_p=init(t, a, (nx<<1)+1, (s+e)/2+1, e);
	t[nx].first=f_p.first<s_p.first ? f_p.first:s_p.first;
	t[nx].second=f_p.second>s_p.second ? f_p.second:s_p.second;
	return t[nx];
}
pii minmax(vii& t, int nx, int s, int e, int l, int r){
	if(l<=s && e<=r)	return t[nx];
	int mid=(s+e)/2;
	if(mid<l){
		return minmax(t, (nx<<1)+1, mid+1, e, l, r);
	}
	else if(mid>=r){
		return minmax(t, nx<<1, s, mid, l, r);
	}
	else{
		pii f_p=minmax(t, (nx<<1), s, mid, l, r);
		pii s_p=minmax(t, (nx<<1)+1, mid+1, e, l, r);
		pii tmp;
		tmp.first=f_p.first<s_p.first ? f_p.first:s_p.first;
		tmp.second=f_p.second>s_p.second ? f_p.second:s_p.second;
		return tmp;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, a, b;
	cin>>N>>M;
	vi A(N);
	int n, size;
	n=(int)ceil(log2(N));
	size=(1<<(n+1));
	vii seg(size);
	pii tmp;
	for(int i=0;i<N;i++)	cin>>A[i];
	init(seg, A, 1, 0, N-1);
	for(int i=0;i<M;i++){
		cin>>a>>b;
		tmp=minmax(seg, 1, 0, N-1, a-1, b-1);
		cout<<tmp.first<<" "<<tmp.second<<"\n";
	}
	return 0;
}
