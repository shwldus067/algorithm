#include<iostream>
#include<algorithm>
using namespace std;
int p, w, s, t, parent[1000];
struct str{
	int u, v, w;
	bool operator<(const str &a)const{
		return w>a.w;
	}
}W[50000];
int find(int u){
	return u==parent[u]?u:find(parent[u]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>p>>w>>s>>t;
	for(int i=0;i<w;++i){
		int a, b, c;
		cin>>a>>b>>c;
		W[i]={a, b, c};
	}
	sort(W, W+w);
	for(int i=0;i<p;++i)	parent[i]=i;
	for(int i=0;i<w;++i){
		int u=find(W[i].u), v=find(W[i].v);
		if(u!=v){
			parent[v]=u;
			if(find(s)==find(t)){
				cout<<W[i].w<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
