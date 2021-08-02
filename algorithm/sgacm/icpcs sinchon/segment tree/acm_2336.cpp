#include<iostream>
#include<algorithm>
using namespace std;
int N, ans, seg[1050000];
struct str{
	int f, s, t;
};
str student[500001];
bool operator<(str& a, str& b){
	return a.f<b.f;
}
int update(int x, int s, int e, int idx, int d){
	if(idx<s || e<idx)	return seg[x];
	if(s==e)	return seg[x]=d;
	int mid=(s+e)/2;
	return seg[x]=min(update(x*2, s, mid, idx, d), update(x*2+1, mid+1, e, idx, d));
}
int query(int x, int s, int e, int l, int r){
	if(r<s || e<l)	return 1e9;
	if(l<=s && e<=r)	return seg[x];
	int mid=(s+e)/2;
	return min(query(x*2, s, mid, l, r), query(x*2+1, mid+1, e, l, r));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<1050000;++i)	seg[i]=1e9;
	cin>>N;
	int t;
	for(int i=1;i<=N;++i){
		cin>>t, student[t].f=i;
	}
	for(int i=1;i<=N;++i){
		cin>>t, student[t].s=i;
	}
	for(int i=1;i<=N;++i){
		cin>>t, student[t].t=i;
	}
	sort(student+1, student+N+1);
	for(int i=1;i<=N;++i){
		if(query(1, 1, N, 1, student[i].s)>student[i].t)
			ans++;
		update(1, 1, N, student[i].s, student[i].t);
	}
	cout<<ans<<"\n";
	return 0;
}
