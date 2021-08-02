#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	char cur=read();
	while(cur==10 || cur==32)	cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	return sum;
}
int N, K, w[100000], ans[100000], xdx, ydx;
pii x[100000], y[100000], ls[100000];
pii X[300000], Y[300000];
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
	int T, M, L, a, b, c, d, t, xbase, ybase;
	T=readInt();
	while(T--){
		N=readInt();K=readInt();L=readInt();M=K+K;
		for(int i=0;i<K;++i){
			a=readInt();b=readInt();c=readInt();d=readInt();w[i]=readInt();
			if(a<c)	x[i]={a, c}, X[i]={a, i}, X[i+K]={c, i+K};
			else	x[i]={c, a}, X[i]={c, i}, X[i+K]={a, i+K};
			if(b<d)	y[i]={b, d}, Y[i]={b, i}, Y[i+K]={d, i+K};
			else	y[i]={d, b}, Y[i]={d, i}, Y[i+K]={b, i+K};
		}
		xdx=ydx=M;
		for(int i=0;i<L;++i){
			ls[i].first=readInt();ls[i].second=readInt();
			if(ls[i].second)	X[xdx++]={ls[i].first, i+M};
			else	Y[ydx++]={ls[i].first, i+M};
			ans[i]=0;
		}
		sort(X, X+xdx);
		sort(Y, Y+ydx);
		int p=0, xs=-1, ss, ys=-1;
		for(int i=0;i<xdx;++i){
			if(p<X[i].first)	p=X[i].first, ++xs;
			ss=X[i].second;
			if(ss<M){
				if(ss<K)	x[ss].first=xs;
				else	x[ss-K].second=xs;
			}else	ls[ss-M].first=xs;
		}
		p=0;
		for(int i=0;i<ydx;++i){
			if(p<Y[i].first)	p=Y[i].first, ++ys;
			ss=Y[i].second;
			if(ss<M){
				if(ss<K)	y[ss].first=ys;
				else	y[ss-K].second=ys;
			}else	ls[ss-M].first=ys;
		}
		++xs, ++ys;
		xbase=ybase=1;
		while(xbase<xs)	xbase*=2;
		while(ybase<ys)	ybase*=2;
		xs=xbase+xbase;
		ys=ybase+ybase;
		for(int i=1;i<xs;++i)	xseg[i]=1e9;
		for(int i=1;i<ys;++i)	yseg[i]=1e9;
		for(int i=0;i<L;++i){
			if(ls[i].second)	update(xseg, ls[i].first, i, xbase);
			else	update(yseg, ls[i].first, i, ybase);
		}
		for(int i=0;i<K;++i){
			t=min(query(xseg, x[i].first, x[i].second, xbase), query(yseg, y[i].first, y[i].second, ybase));
			if(t==1e9)	continue;
			ans[t]=max(ans[t], w[i]);
		}
		for(int i=0;i<L;++i)	printf("%d\n", ans[i]);
	}
	return 0;
}
