#include<iostream>
using namespace std;
typedef long long ll;
ll inf=(1ll<<60);
ll ninf=-inf;
int N, S, T, M;
ll d[100], arr[100];
struct edge{
	int s, t;
	ll w;
}e[100];
void bellmanford(){
	for(int i=0;i<N;++i)	d[i]=ninf;
	d[S]=arr[S];
	for(int i=0;i<N+N;++i){
		for(int j=0;j<M;++j){
			if(d[e[j].s]==ninf)	continue;
			if(d[e[j].s]==inf)	d[e[j].t]=inf;
			else if(d[e[j].t]<d[e[j].s]+e[j].w){
				if(i<N)	d[e[j].t]=d[e[j].s]+e[j].w;
				else	d[e[j].t]=inf;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>S>>T>>M;
	for(int i=0;i<M;++i){
		int a, b, c;
		cin>>a>>b>>c;
		e[i]={a, b, -c};
	}
	for(int i=0;i<N;++i)	cin>>arr[i];
	for(int i=0;i<M;++i){
		e[i].w+=arr[e[i].t];
	}
	bellmanford();
	if(d[T]==inf)	cout<<"Gee\n";
	else if(d[T]==ninf)	cout<<"gg\n";
	else	cout<<d[T]<<"\n";
	return 0;
}
