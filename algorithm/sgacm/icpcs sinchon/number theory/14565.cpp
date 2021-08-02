#include <stdio.h>

long long int A, N;

long long int mul(long long int a, long long int b){
	if(b == 0) return 0;
	long long int t = mul(a, b/2);
	if(b % 2 == 0) return (t+t)%N;
	return (t+t+a)%N;
}

long long int pow(long long int x){
	if(x == 0) return 1;
	long long int t = pow(x/2);
	if(x % 2 == 0) return mul(t, t);
	return mul(t, mul(t, A));
}

long long int gcd(long long int a, long long int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

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
	long long int phi;
	scanf("%lld%lld", &N, &A);

	printf("%lld ", (N-A+N)%N); // inverse +

	if(gcd(N, A)!=1){
		printf("-1\n");
		return 0;
	}
	

	phi = totient(N);

	printf("%lld\n", pow(phi-1));
	return 0;
}