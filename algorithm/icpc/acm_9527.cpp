#include<cstdio>
int main(){
	long long A, B, na=0, nb=0, i, j;
	scanf("%lld %lld", &A, &B);
	for(i=1;i<=B;i<<=1){
		nb+=B/(i<<1)*i;
		j=B%(i<<1);
		if(j>=i)	nb+=j-i+1;
	}
	--A;
	for(i=1;i<=A;i<<=1){
		na+=A/(i<<1)*i;
		j=A%(i<<1);
		if(j>=i)	na+=j-i+1;
	}
	printf("%lld\n", nb-na);
	return 0;
}
