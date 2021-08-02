#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
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
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pip;
pii x[100000], y[100000], z[100000];
pip adj[300000];
int p[100000];
int find(int u){
	int &ret=p[u];
	while(ret!=p[ret])	ret=p[ret];
	return ret;
}
inline int abs(int k){return k<0?-k:k;}
int main(){
	int N, M=0, cnt=1;
	long long ans=0;
	N=readInt();
	for(int i=0;i<N;++i){
		x[i].first=readInt();y[i].first=readInt();z[i].first=readInt();
		x[i].second=y[i].second=z[i].second=i;
		p[i]=i;
	}
	sort(x, x+N);sort(y, y+N);sort(z, z+N);
	for(int i=1;i<N;++i){
		adj[M++]={abs(x[i].first-x[i-1].first), {x[i].second, x[i-1].second}};
		adj[M++]={abs(y[i].first-y[i-1].first), {y[i].second, y[i-1].second}};
		adj[M++]={abs(z[i].first-z[i-1].first), {z[i].second, z[i-1].second}};
	}
	sort(adj, adj+M);
	for(int i=0;i<M;++i){
		int u=find(adj[i].second.first), v=find(adj[i].second.second);
		if(u==v)	continue;
		ans+=adj[i].first;
		if(u<v)	p[v]=u;
		else	p[u]=v;
		if(++cnt==N)	break;
	}
	printf("%d\n", ans);
	return 0;
}
