#include <stdio.h>

long long int totient(long long int N){
	long long int res = N;

	for(int i = 2; 1LL*i*i <= N; i++){
		if(N % i) continue;
		while(N % i == 0) N /= i;
		res = res/i*(i-1);
	}

	if(N != 1) res = res/N*(N-1);

	return res;
}

int main(){
	long long int N;
	scanf("%lld", &N);

	printf("%lld\n", totient(N));
}