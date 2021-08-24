#include<cstdio>
int main(){
	int N, P[48], S[48], A[48];
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", P+i);
	for(int i=0;i<N;++i)	scanf("%d", S+i), A[i]=i;
	int cnt=0;
	while(1){
		int i;
		for(i=0;i<N;++i)if(A[i]%3!=P[i])	break;
		if(i==N)	break;
		for(i=0;i<N;++i)	A[i]=S[A[i]];
		for(i=0;i<N;++i)if(i!=A[i])	break;
		if(i==N){
			cnt=-1;
			break;
		}
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
