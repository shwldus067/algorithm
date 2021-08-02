#include <stdio.h>

bool isPrime[250000]; // 0 if prime number 1 o/w

void seive(){
	isPrime[1] = 1;
	for(int i = 2; i < 250000; i++){
		if(isPrime[i]) continue;
		for(int j = i+i; j < 250000; j += i){
			isPrime[j] = 1;
		}
	}
}

int main(){
	int N, ans;
	seive();

	while(true){
		scanf("%d", &N);
		if(N == 0) break;

		ans = 0;
		for(int i = N+1; i <= 2*N; i++){
			if(isPrime[i] == 0) ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}