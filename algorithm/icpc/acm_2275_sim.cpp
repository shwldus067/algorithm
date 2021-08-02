#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int N, H, p[10000], d[10000], ind[10000]={0, }, val[10000];
	scanf("%d %d", &N, &H);
	for(int i=0;i<N;++i){
		scanf("%d %d", p+i, d+i);
		if(--p[i]>=0)	++ind[p[i]];
		val[i]=2e9;
	}
	queue<int> Q;
	for(int i=0;i<N;++i){
		if(ind[i]==0)	Q.push(i), val[i]=H;
	}
	int ans=0;
	while(Q.size()){
		int cur=Q.front();Q.pop();
		if(p[cur]<0)	break;
		int nxt=p[cur];
		ans+=max(d[cur]-val[cur], 0);
		val[nxt]=min(max(val[cur]-d[cur], 0), val[nxt]);
		if(--ind[nxt]==0)	Q.push(nxt);
	}
	printf("%d\n", ans);
	return 0;
}
