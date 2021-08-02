#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll inf=1ll<<60;
const ll ninf=-inf;
int N, M, p[101], ans[101], cnt[101];
ll d[101];
vector<pii> edge[101];
vector<int> cycle;
bool visit[101];
bool dfs(int cur){
	if(cur==N){
		return true;
	}
	for(pii &next:edge[cur]){
		if(!visit[next.first]){
			visit[next.first]=true;
			if(dfs(next.first))	return true;
		}
	}
	return false;
}
void spfa(){
	for(int i=1;i<=N;++i)	d[i]=ninf;
	d[1]=0, cnt[1]=1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(cnt[j]!=i)	continue;
			for(pii &next:edge[j]){
				int dist=d[j]+next.second;
				if(dist>d[next.first]){
					d[next.first]=dist;
					cnt[next.first]=i+1;
					p[next.first]=j;
					if(i==N)	cycle.push_back(next.first);
				}
			}
		}
	}
	if(d[N]==ninf)	return;
	for(int s:cycle){
		for(int i=0;i<=N;++i)	visit[i]=0;
		visit[s]=true;
		if(dfs(s)){
			d[N]=inf;
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a, b, c;
		cin>>a>>b>>c;
		edge[a].push_back({b, c});
	}
	spfa();
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
