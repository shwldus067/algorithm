#include<stdio.h>
int main(){
	int n, W, s;
	scanf("%d %d", &n, &W);
	long long q=0, p=W, r=0;
	for(int i=0;i<n;++i){
		scanf("%d", &s);
		if(p<q*s)
			p=q*s;
		else
			q=(p+r)/s, r=(p+r)%s, p=q*s;
	}
	printf("%lld\n", p+r);
	return 0;
}
