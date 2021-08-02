#include<cstdio>
int main(){
	int N, M, K, L, R, A[100001], B[100001], S, t;
	scanf("%d %d %d", &N, &M, &K);
	++N;
	for(int i=1;i<N;++i)	A[i]=i, B[i]=0;
	while(M--){
		scanf("%d %d", &L, &R);
		S=(R-L+1)/2;
		for(int i=0;i<S;++i)	t=A[L+i], A[L+i]=A[R-i], A[R-i]=t;
	}
	for(int i=1;i<N;++i){
		if(B[i])	continue;
		int k=i, cnt=0;
		while(1){
			k=A[k];
			++cnt;
			if(k==i || cnt==K)	break;
		}
		if(cnt!=K)	for(int j=0;j<K%cnt;++j)	k=A[k];
		B[i]=k;
		k=i;
		while(1){
			B[A[k]]=A[B[k]];
			k=A[k];
			if(k==i)	break;
		}
	}
	for(int i=1;i<N;++i)	printf("%d\n", B[i]);
	return 0;
}
