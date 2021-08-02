#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, K, w[100000], ans[100000];
pii x[100000], y[100000], ls[100000];
vector<int> X, Y;
int xseg[1<<20], yseg[1<<20];
void update(int *seg, int idx, int d, int base){
	int i=idx+base;
	seg[i]=min(seg[i], d);
	for(i>>=1;i;i>>=1){
		int j=i*2;
		seg[i]=min(seg[j], seg[j+1]);
	}
}
int query(int *seg, int l, int r, int base){
	int ret=1e9;
	l+=base;r+=base;
	while(l<=r){
		if(l&1)	ret=min(ret, seg[l++]);
		if(!(r&1))	ret=min(ret, seg[r--]);
		l>>=1, r>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, M, L, a, b, c, d, t, xbase, ybase;
	cin>>T;
	while(T--){
		X.clear();Y.clear();
		cin>>N>>K>>L;
		for(int i=0;i<K;++i){
			cin>>a>>b>>c>>d>>w[i];
			if(a<c)	x[i]={a, c};
			else	x[i]={c, a};
			if(b<d)	y[i]={b, d};
			else	y[i]={d, b};
			X.push_back(a);X.push_back(c);
			Y.push_back(b);Y.push_back(d);
		}
		for(int i=0;i<L;++i){
			cin>>ls[i].first>>ls[i].second;
			if(ls[i].second)	X.push_back(ls[i].first);
			else	Y.push_back(ls[i].first);
			ans[i]=0;
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		int xs=X.size(), ys=Y.size();
		xbase=ybase=1;
		while(xbase<xs)	xbase*=2;
		while(ybase<ys)	ybase*=2;
		xs=xbase+xbase;
		ys=ybase+ybase;
		for(int i=1;i<xs;++i)	xseg[i]=1e9;
		for(int i=1;i<ys;++i)	yseg[i]=1e9;
		for(int i=0;i<L;++i){
			if(ls[i].second)	update(xseg, lower_bound(X.begin(), X.end(), ls[i].first)-X.begin(), i, xbase);
			else	update(yseg, lower_bound(Y.begin(), Y.end(), ls[i].first)-Y.begin(), i, ybase);
		}
		for(int i=0;i<K;++i){
			t=min(query(xseg, lower_bound(X.begin(), X.end(), x[i].first)-X.begin(), lower_bound(X.begin(), X.end(), x[i].second)-X.begin(), xbase), 
				  query(yseg, lower_bound(Y.begin(), Y.end(), y[i].first)-Y.begin(), lower_bound(Y.begin(), Y.end(), y[i].second)-Y.begin(), ybase));
			if(t==1e9)	continue;
			ans[t]=max(ans[t], w[i]);
		}
		for(int i=0;i<L;++i)	cout<<ans[i]<<"\n";
	}
	return 0;
}
