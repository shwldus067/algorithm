#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
struct bd{
	int lx, rx, h;
	bool operator<(bd &a){
		return make_tuple(lx, h, rx)<make_tuple(a.lx, a.h, a.rx);
	}
}A[100000];
void append(vii &ans, pii p){
	int n=ans.size();
	if(n>0){
		if(ans[n-1].second==p.second)	return;
		if(ans[n-1].first==p.first){
			ans[n-1].second=p.second;
			return;
		}
	}
	ans.push_back(p);
}
vii merge(vii &l, vii &r){
	vii ans;
	int h1=0, h2=0;
	int i=0, j=0;
	while(i<l.size() && j<r.size()){
		pii &u=l[i];
		pii &v=r[j];
		if(u.first<v.first){
			h1=u.second;
			append(ans, pii(u.first, max(h1, h2)));
			++i;
		}
		else{
			h2=v.second;
			append(ans, pii(v.first, max(h1, h2)));
			++j;
		}
	}
	while(i<l.size()){
		append(ans, l[i++]);
	}
	while(j<r.size()){
		append(ans, r[j++]);
	}
	return ans;
}
vii f(int s, int e){
	if(s==e){
		vii ans={{A[s].lx, A[s].h}, {A[s].rx, 0}};
		return ans;
	}
	int m=(s+e)/2;
	vii l=f(s, m);
	vii r=f(m+1, e);
	return merge(l, r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i].lx>>A[i].h>>A[i].rx;
	}
	sort(A, A+N);
	vii ans=f(0, N-1);
	for(pii &p:ans){
		cout<<p.first<<' '<<p.second<<' ';
	}
	cout<<"\n";
	return 0;
}
