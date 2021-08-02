#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N, M, K, S, E, p[20000], e[20000];
int dr[4]={-1, 0, 0, 1}, dc[4]={0, 1, -1, 0};
char arr[100][101];
vector<int> adj[20000];
bool v[20000];
int sol(){
	int ans=0;
	p[S]=-1;
	K=N*M*2;
	while(1){
		for(int i=0;i<K;++i)	v[i]=0;
		queue<int> Q;
		Q.push(S);
		v[S]=1;
		while(Q.size()){
			int cur=Q.front();
			if(cur==E)	break;
			Q.pop();
			for(int i=0;i<adj[cur].size();++i){
				int n=adj[cur][i];
				if(!v[n]){
					v[n]=1;
					Q.push(n);
					p[n]=cur;
					e[n]=i;
				}
			}
		}
		if(Q.size()){
			++ans;
			int f=p[E], t=E;
			while(f>=0){
				adj[f][e[t]]=adj[f].back();
				adj[f].pop_back();
				adj[t].push_back(f);
				t=f, f=p[f];
			}
		}
		else	return ans;
	}
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)	scanf("%s", arr[i]);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(arr[i][j]=='#')	continue;
			int k=(i*M+j)*2;
			adj[k].push_back(k+1);
			if(arr[i][j]=='K'){
				S=k+1;
				for(int d=0;d<4;++d){
					int ni=i+dr[d], nj=j+dc[d];
					if(ni<0 || ni>=N || nj<0 || nj>=M)	continue;
					if(arr[ni][nj]=='H'){
						printf("-1\n");
						return 0;
					}
				}
			}
			else if(arr[i][j]=='H')	E=k;
			for(int d=0;d<4;++d){
				int r=i+dr[d], c=j+dc[d];
				if(r<0 || r>=N || c<0 || c>=M)	continue;
				if(arr[r][c]=='#')	continue;
				adj[k+1].push_back((r*M+c)*2);
			}
		}
	}
	printf("%d\n", sol());
	return 0;
}
