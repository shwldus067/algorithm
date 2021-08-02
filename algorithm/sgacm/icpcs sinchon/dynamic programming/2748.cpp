#include <stdio.h>
#define MAX 100

long long int fibo[MAX];

int main(){
	int n;
	scanf("%d", &n);

	fibo[0] = 0;
	fibo[1] = 1;

	for(int i = 2; i <= n; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}

	printf("%lld\n", fibo[n]);
}