#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, sv, ev;
int d[10001], ind[10001];
bool ch[10001];
vector<pair<int, int> > adj[10001], radj[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	while(m--){
		int a, b, c;
		cin>>a>>b>>c;
		ind[b]++;
		adj[a].push_back({b, c});
		radj[b].push_back({a, c});
	}
	cin>>sv>>ev;
	queue<int> Q;
	Q.push(sv);
	int cur, num, next, nnum;
	while(Q.size()){
		cur=Q.front();
		Q.pop();
		for(int i=adj[cur].size()-1;i>=0;i--){
			next=adj[cur][i].first;
			nnum=adj[cur][i].second+d[cur];
			if(d[next]<=nnum){
				d[next]=nnum;
			}
			if(--ind[next]==0)	Q.push(next);
		}
	}
	Q.push(ev);
	int ans=0;
	while(Q.size()){
		cur=Q.front();
		Q.pop();
		if(ch[cur])	continue;
		ch[cur]=true;
		for(int i=radj[cur].size()-1;i>=0;i--){
			next=radj[cur][i].first;
			nnum=d[cur]-radj[cur][i].second;
			if(d[next]==nnum){
				Q.push(next);
				ans++;
			}
		}
	}
	cout<<d[ev]<<"\n"<<ans<<"\n";
	return 0;
}
