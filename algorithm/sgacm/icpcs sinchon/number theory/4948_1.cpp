#include <stdio.h>

bool is_prime(int num){
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0) return false;
	}
	return true;
}

int main(){
	int N, ans;

	while(true){
		scanf("%d", &N);
		if(N == 0) return 0;

		ans = 0;

		for(int i = N+1; i <= 2*N; i++){
			if(is_prime(i)) ans++;
		}

		printf("%d\n", ans);
	}
}