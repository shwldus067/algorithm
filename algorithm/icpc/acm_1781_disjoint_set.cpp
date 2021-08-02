#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, ans=0;
pii arr[200001];
int parent[200001], r[200001], s[200001];
int find(int u){
	while(u!=parent[u])	u=parent[u];
	return u;
}
void merge(int u, int v){
	u=find(u);
	v=find(v);
	if(u==v)	return;
	if(r[u]>r[v]){
		parent[v]=u;
		if(s[u]>s[v])	s[u]=s[v];
	}
	else if(r[u]<r[v]){
		parent[u]=v;
		if(s[v]>s[u])	s[v]=s[u];
	}
	else{
		parent[v]=u;
		if(s[u]>s[v])	s[u]=s[v];
		r[u]++;
	}
}
bool cmp(pii &a, pii &b){
	return a.second>b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i].first>>arr[i].second;
		parent[i]=i;
		s[i]=i;
	}
	sort(arr+1, arr+N+1, cmp);
	for(int i=1;i<=N;i++){
		int dl=arr[i].first;
		int p=s[find(dl)];
		if(p==0)	continue;
		merge(p, p-1);
		ans+=arr[i].second;
	}
	cout<<ans<<"\n";
	return 0;
}
