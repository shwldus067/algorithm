#include<iostream>
using namespace std;
int G, P, t, parent[100001], cnt;
int find(int u){
	if(parent[u]==u)	return u;
	return parent[u]=find(parent[u]);
}
void merge(int u, int v){
	u=find(u);
	v=find(v);
	parent[u]=v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>G>>P;
	for(int i=1;i<=G;i++)	parent[i]=i;
	while(P--){
		cin>>t;
		int x=find(t);
		if(x==0){
			cout<<cnt<<"\n";
			return 0;
		}
		cnt++;
		merge(x, x-1);
	}
	cout<<cnt<<"\n";
	return 0;
}
