#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int N, d[100001], last[100001];
vector<int> adj[100001];
bool visit[100001];
stack<int> S;
bool cmp(int a, int b){
	return d[a]<d[b];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<N;){
		int x;
		cin>>x;
		d[x]=++i;
	}
	if(d[1]!=1){
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=N;++i){
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	S.push(1);
	visit[1]=1;
	int cnt=2;
	while(S.size()){
		int cur=S.top();
		for(int i=last[cur];i<adj[cur].size();++i){
			int next=adj[cur][i];
			if(i==adj[cur].size()-1)	S.pop();
			if(!visit[next]){
				if(d[next]!=cnt){
					cout<<"0\n";
					return 0;
				}
				visit[next]=1;
				S.push(next);
				last[cur]=i+1;
				++cnt;
				break;
			}
		}
	}
	cout<<"1\n";
	return 0;
}
