#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int tc, N, M, ind[501], res[501];
bool nxt[501][501];
bool chk[501];
vector<int> adj[501];
queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	bool chg=false;
	while(tc--){
		cin>>N;
		if(chg){
			for(int i=1;i<=N;++i){
				chk[i]=false;
				ind[i]=0;
				for(int j=1;j<=N;++j){
					nxt[i][j]=false;
				}
				adj[i].clear();
			}
			queue<int> qu;
			swap(Q, qu);
		}
		chg=true;
		for(int i=0;i<N;++i){
			int t;
			cin>>t;
			chk[t]=true;
			for(int j=1;j<=N;++j){
				if(!chk[j])	nxt[t][j]=true;
			}
		}
		cin>>M;
		bool flag=false;
		while(M--){
			int a, b;
			cin>>a>>b;
			if(nxt[b][a]){
				nxt[b][a]=false;
				nxt[a][b]=true;
			}
			else{
				nxt[a][b]=false;
				nxt[b][a]=true;
			}
		}
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				if(nxt[i][j]){
					adj[i].push_back(j);
					ind[j]++;
				}
			}
		}
		for(int i=1;i<=N;++i){
			if(ind[i]==0){
				Q.push(i);
			}
		}
		int cnt=0;
		while(Q.size()==1){
			int cur=Q.front();
			res[cnt++]=cur;
			Q.pop();
			for(int x:adj[cur]){
				if(--ind[x]==0){
					Q.push(x);
				}
			}
		}
		if(cnt!=N){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			for(int i=0;i<N;++i){
				cout<<res[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
