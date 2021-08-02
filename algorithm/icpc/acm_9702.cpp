#include<stdio.h>
#include<algorithm>
using namespace std;
int T, N, S[500], a[500];
int main(){
	scanf("%d", &T);
	for(int t=0;t<T;++t){
		scanf("%d", &N);
		for(int i=0;i<N;++i)	scanf("%d", S+i);
		int ans=N;
		for(int s=0;s<N-1;++s){
			int idx=1;
			a[0]=S[s];
			for(int i=s+1;i<N;++i){
				if(S[i]>a[idx-1]){
					a[idx++]=S[i];
				}
				else{
					int t=lower_bound(a, a+idx, S[i])-a;
					a[t]=S[i];
				}
				ans+=idx;
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
