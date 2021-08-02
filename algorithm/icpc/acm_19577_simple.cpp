#include<cstdio>
#include<algorithm>
using namespace std;
int num[1400], cnt;
int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int i=1;i*i<=n;++i){
		if(n%i==0)	num[cnt++]=i, num[cnt++]=n/i;
	}
	sort(num, num+cnt);
	for(int i=0;i<cnt;++i){
		int t=num[i];
		int pi=t;
		for(int j=1;j<cnt;++j){
			int p=num[j];
			if(t<p)	break;
			if(t%p==0){
				pi=pi/p*(p-1);
				while(t%p==0)	t/=p;
			}
		}
		if(1ll*num[i]*pi==n){
			printf("%d\n", num[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
