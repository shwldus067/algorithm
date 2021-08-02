#include<iostream>
#include<vector>
using namespace std;
typedef vector<pair<int, char> >	vic;
typedef pair<int, char> pic;
int N, M;
vic adj[20];
int dp[20][20];
bool ch[20][20];
int func(int s, int e){
	if(s==e)	return 0;
	int &ret=dp[s][e];
	if(ret!=-1)	return ret;
	int ans;
	pic u, v;
	ch[s][e]=true;
	for(int i=0;i<adj[s].size();i++){
		u=adj[s][i];
		if(u.first==e){
			ret=1;
			break;
		}
		for(int j=0;j<adj[e].size();j++){
			v=adj[e][j];
			if(u.second!=v.second || ch[u.first][v.first])
				continue;
			ans=func(u.first, v.first);
			if(ans==-1)	continue;
			if(ret==-1 || ret>ans+2){
				ret=ans+2;
			}
		}
	}
	ch[s][e]=false;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int a, b;
	char c;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	fill(&dp[0][0], &dp[19][20], -1);
	cout<<func(0, 1)<<"\n";
	return 0;
}
