#include<cstdio>
#include<algorithm>
using namespace std;
int N, M;
int inp[8], arr[8], c;
void sol(int n, int k){
	if(n==M){
		for(int i=0;i<M;++i)	printf("%d ", inp[i]);
		printf("\n");
		return;
	}
	for(int i=k;i<c;++i){
		inp[n]=arr[i];
		sol(n+1, i);
	}
	return;
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i){
		scanf("%d", &inp[i]);
	}
	sort(inp, inp+N);
	arr[c++]=inp[0];
	for(int i=1;i<N;++i){
		if(inp[i-1]-inp[i])	arr[c++]=inp[i];
	}
	sol(0, 0);
	return 0;
}
