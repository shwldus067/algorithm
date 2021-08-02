#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N, H, root=0, par[10001][2];
vector<pair<int, int> > adj[10001];
vector<pair<int, int> > leaf;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>H;
	for(int i=1;i<=N;++i){
		int a, b;
		cin>>a>>b;
		if(a==0)	root=i;
		else{
			adj[a].push_back({i, b});
			par[i][0]=a, par[i][1]=b;
		}
	}
	queue<pair<int, int> > Q;
	Q.push({root, 0});
	while(Q.size()){
		int cur=Q.front().first, sum=Q.front().second;
		Q.pop();
		if(adj[cur].size()==0){
			leaf.push_back({cur, sum});continue;
		}
		for(pair<int, int> &nxt:adj[cur]){
			Q.push({nxt.first, sum+nxt.second});
		}
	}
	int ans=0;
	stack<pair<int, int *> > st;
	for(pair<int, int> &lf:leaf){
		int cur=lf.first, w=0;
		int *cost;
		while(cur!=root){
			st.push({cur, &par[cur][1]});
			w+=par[cur][1];
			cur=par[cur][0];
		}
		if(w<=H){
			while(st.size())	st.pop();
			continue;
		}
		while(st.size()){
			cur=st.top().first, cost=st.top().second;
			st.pop();
			if(*cost && w>H){
				if(*cost>w-H)	ans+=w-H, *cost-=w-H, w=H;
				else	ans+=*cost, w-=*cost, *cost=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
