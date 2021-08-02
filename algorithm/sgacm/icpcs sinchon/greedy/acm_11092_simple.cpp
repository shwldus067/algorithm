#include<cstdio>
#include<algorithm>
using namespace std;
int N, a[15];
int main(){
	scanf("%d", &N);
	int i, ans=0;
	for(i=0;i<N;++i)	scanf("%d", &a[i]);
	sort(a, a+N);
	for(i=N-1;i>1;i-=2){
		ans+=min(a[0]+a[1]*2+a[i], a[0]*2+a[i-1]+a[i]);
	}
	if(i==1)	ans+=a[1];
	else 	ans-=a[0];
	printf("%d\n", ans);
	return 0;
}
