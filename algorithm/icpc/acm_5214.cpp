#include<iostream>
#include<queue>
using namespace std;
vector<int> adj[101001];
bool visit[101001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, M, ans=0, arr[1000], sz, f=0;
	cin>>N>>K>>M;
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	for(int i=0;i<M;++i){
		int t=i+100001, a;
		for(int j=0;j<K;++j){
			cin>>a;
			adj[t].push_back(a);
			adj[a].push_back(t);
		}
	}
	queue<int> Q;
	Q.push(1);
	visit[1]=1;
	while(sz=Q.size()){
		while(sz--){
			int cur=Q.front();Q.pop();
			if(cur==N){
				f=1;break;
			}
			for(int nxt:adj[cur]){
				if(visit[nxt])	continue;
				visit[nxt]=1;
				Q.push(nxt);
			}
		}
		if(f)	break;
		++ans;
	}
	if(visit[N])	cout<<ans/2+1<<"\n";
	else	cout<<"-1\n";
	return 0;
}
