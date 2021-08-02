#include<iostream>
using namespace std;
int T, n, visit[26], parent[26], dp[26];
bool chk[26][26];
int dfs(int u, int p){
	if(visit[u]==2)	return -1;
	parent[u]=p;
	if(visit[u]==1)	return u;
	visit[u]=1;
	int ret=-1;
	for(int i=0;i<26;++i){
		if(chk[u][i]){
			if((ret=dfs(i, u))!=-1) return ret;
			dp[u]=max(dp[u], dp[i]+1);
		}
	}
	visit[u]=2;
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<26;++i){
			visit[i]=dp[i]=0;
			for(int j=0;j<26;++j){
				chk[i][j]=true;
			}
		}
		while(n--){
			char x, y;
			cin>>x>>y;
			chk[x-'a'][y-'a']=false;
		}
		int cycle=-1;
		for(int i=0;i<26;++i){
			if((cycle=dfs(i, -1))!=-1)	break;
		}
		int res[100], idx=0;
		if(cycle!=-1){
			idx=39;
			for(int i=idx-1;i>=0;--i){
				res[i]=cycle;
				cycle=parent[cycle];
			}
		}
		else{
			int u=0;
			for(int i=0;i<26;++i){
				if(dp[i]>dp[u]) u=i;
			}
			while(dp[u]>0){
				res[idx++]=u;
				for(int i=0;i<26;++i){
					if(chk[u][i] && dp[i]+1==dp[u]){
						u=i;
						break;
					}
				}
			}
			res[idx++]=u;
		}
		idx=(idx+1)/2;
		for(int i=0;i<idx;++i){
			for(int j=0;j<idx;++j){
				cout<<(char)('a'+res[i+j]);
			}
			cout<<"\n";
		}
	}
	return 0;
}
