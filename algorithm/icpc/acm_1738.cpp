#include<iostream>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
const ll ninf=-inf;
int N, M, p[101], ans[101];
ll d[101];
struct edge{
	int u, v, w;
}e[20000];
void bellmanford(){
	for(int i=1;i<=N;++i)	d[i]=ninf;
	d[1]=0;
	for(int k=0;k<N+N;++k){
		for(int i=0;i<M;++i){
			if(d[e[i].u]==ninf)	continue;
			if(d[e[i].u]==inf)	d[e[i].v]=inf;
			else if(d[e[i].v]<d[e[i].u]+e[i].w){
				if(k<N)	d[e[i].v]=d[e[i].u]+e[i].w, p[e[i].v]=e[i].u;
				else	d[e[i].v]=inf;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bellmanford();
	if(d[N]==ninf || d[N]==inf)	cout<<"-1\n";
	else{
		int idx=0;
		for(int i=N;i;i=p[i]){
			ans[idx++]=i;
		}
		for(int i=idx-1;~i;--i){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
