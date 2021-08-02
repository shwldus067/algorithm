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
int N, K, w[100000], ans[100000];
pii x[100000], y[100000], lx[100000], ly[100000];
int xseg[1<<18], yseg[1<<18];
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
	int T, L, a, b, c, d, t, xbase, ybase;
	T=readInt();
	while(T--){
		N=readInt();K=readInt();L=readInt();
		for(int i=0;i<K;++i){
			a=readInt();b=readInt();c=readInt();d=readInt();w[i]=readInt();
			if(a<c)	x[i]={a, c};
			else	x[i]={c, a};
			if(b<d)	y[i]={b, d};
			else	y[i]={d, b};
		}
		int xs=0, ys=0;
		for(int i=0;i<L;++i){
			a=readInt();b=readInt();
			if(b)	lx[xs++]={a, i};
			else	ly[ys++]={a, i};
			ans[i]=0;
		}
		sort(lx, lx+xs);
		sort(ly, ly+ys);
		xbase=ybase=1;
		while(xbase<xs)	xbase*=2;
		while(ybase<ys)	ybase*=2;
		a=xbase+xbase;
		b=ybase+ybase;
		for(int i=1;i<a;++i)	xseg[i]=1e9;
		for(int i=1;i<b;++i)	yseg[i]=1e9;
		for(int i=0;i<xs;++i)	update(xseg, i, lx[i].second, xbase);
		for(int i=0;i<ys;++i)	update(yseg, i, ly[i].second, ybase);
		for(int i=0;i<K;++i){
			int s=lower_bound(lx, lx+xs, make_pair(x[i].first, -1))-lx;
			int e=upper_bound(lx, lx+xs, make_pair(x[i].second, 1000000000))-lx;
			if(s==e)	t=1e9;
			else	t=query(xseg, s, --e, xbase);
			s=lower_bound(ly, ly+ys, make_pair(y[i].first, -1))-ly;
			e=upper_bound(ly, ly+ys, make_pair(y[i].second, 1000000000))-ly;
			if(s==e)	t=min(t, 1000000000);
			else	t=min(t, query(yseg, s, --e, ybase));
			if(t==1e9)	continue;
			ans[t]=max(ans[t], w[i]);
		}
		for(int i=0;i<L;++i)	printf("%d\n", ans[i]);
	}
	return 0;
}
