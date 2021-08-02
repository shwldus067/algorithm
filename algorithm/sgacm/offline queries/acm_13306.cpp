#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, Q;
pii query[200000];
int parent[200001];
int d[200000], input[200001], r[200000];
bool ch[400000], ans[200000];
int find(int u){
	int v=u;
	while(v!=parent[v]){
		v=parent[v];
	}
	return v;
}
void merge(int u, int v){
	u=find(u);
	v=find(v);
	if(u==v)	return;
	if(r[u]>r[v]){
		parent[v]=u;
	}
	else{
		parent[u]=v;
		if(r[u]==r[v])	r[v]++;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	int a, q_c=0, d_c=0, u, v;
	for(int i=1;i<=N;i++)	parent[i]=i;
	for(int i=2;i<=N;i++){
		cin>>input[i];
	}
	for(int i=0;i<N+Q-1;i++){
		cin>>a;
		if(a==1){
			cin>>query[q_c].first>>query[q_c].second;
			ch[i]=true;
			q_c++;
		}
		else{
			cin>>d[d_c++];
		}
	}
	q_c--, d_c--;
	for(int i=N+Q-2;i>=0;i--){
		if(ch[i]){
			u=find(query[q_c].first);
			v=find(query[q_c].second);
			if(u==v)	ans[q_c]=true;
			q_c--;
		}
		else{
			u=d[d_c--];
			merge(u, input[u]);
		}
	}
	for(int i=0;i<Q;i++){
		if(ans[i])	cout<<"YES\n";
		else	cout<<"NO\n";
	}
	return 0;
}
