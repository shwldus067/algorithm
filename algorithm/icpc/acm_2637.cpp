#include<cstdio>
#include<vector>
using namespace std;
char ind[100];
int ans[100];
int main(){
	vector<pair<int, int> > nxt[100];
	int N, M, X, Y, K;
	char Q[100], l=0, r=1;
	scanf("%d %d", &N, &M);
	while(M--){
		scanf("%d %d %d", &X, &Y, &K);
		--X, --Y;
		nxt[X].push_back({Y, K});
		++ind[Y];
	}
	Q[0]=N-1;
	ans[N-1]=1;
	while(l<r){
		int cur=Q[l++];
		for(pair<int, int> &p:nxt[cur]){
			ans[p.first]+=p.second*ans[cur];
			if(--ind[p.first]==0)	Q[r++]=p.first;
		}
	}
	for(int i=0;i<N;++i){
		if(nxt[i].size()==0)	printf("%d %d\n", i+1, ans[i]);
	}
	return 0;
}
