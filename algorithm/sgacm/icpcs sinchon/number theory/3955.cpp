#include <stdio.h>

long long int C, K;
long long int extendedEuclid(long long int a, long long int b, long long int &x, long long int &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	long long int gcd = extendedEuclid(b, a%b, x, y);
	long long int tmp = y;
	y = x - (a/b)*y;
	x = tmp;

	/***** handle the case w/ x is less or equal to the 0 ******/
	/***** Thus it is not neccesary in general extended Euclid **********/
	if(x <= 0){
		x += b;
		y -= a;
	}
	return gcd;
}

int main(){
	long long int x, y, g;
	long long int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &K, &C);
		if(K == 1){
			printf("%d\n", 2);
			continue;
		}
		if(C == 1){
			if(K == 1000000000) puts("IMPOSSIBLE");
			else printf("%d\n", K+1);
			continue;
		}
		g = extendedEuclid(C, K, x, y);
		if(g != 1 || x > 1000000000){
			puts("IMPOSSIBLE");
			continue;
		}
		printf("%lld\n", x, y);
	}
}