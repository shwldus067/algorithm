#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int N, M, a, b, c, ind[1001]={0, }, arr[1000], idx=0;
	scanf("%d %d", &N, &M);
	vector<int> vec[N+1];
	while(M--){
		scanf("%d", &a);
		if(a==0)	continue;
		a--;
		scanf("%d", &b);
		while(a--){
			scanf("%d", &c);
			ind[c]++;
			vec[b].push_back(c);
			b=c;
		}
	}
	queue<int> Q;
	for(int i=1;i<=N;++i)	if(ind[i]==0)	Q.push(i);
	while(Q.size()){
		int cur=Q.front();Q.pop();
		arr[idx++]=cur;
		for(int nxt:vec[cur]){
			if(!(--ind[nxt])){
				Q.push(nxt);
			}
		}
	}
	if(idx<N)	printf("0\n");
	else{
		for(int i=0;i<idx;++i)	printf("%d\n", arr[i]);
	}
	return 0;
}
