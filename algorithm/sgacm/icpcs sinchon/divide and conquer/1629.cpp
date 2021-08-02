#include <stdio.h>

typedef long long int lli;

lli A, B, C;

lli pow(lli B){
	if(B == 0) return 1LL;
	lli tmp = pow(B/2);
	if(B % 2 == 0) return tmp*tmp%C;
	return tmp*tmp%C*A%C;
}

int main(){
	scanf("%lld%lld%lld", &A, &B, &C);
	printf("%lld\n", pow(B));
}