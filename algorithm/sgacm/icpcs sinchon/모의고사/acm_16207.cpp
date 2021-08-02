#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[100001];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+N);
	int a=0, b=0;
	long long ans=0;
	for(int i=N-1;i>0;--i){
		if(arr[i]==arr[i-1]){
			if(a)	b=arr[i];
			else	a=arr[i];
			i--;
		}
		else if(arr[i]-1==arr[i-1]){
			if(a)	b=arr[i-1];
			else	a=arr[i-1];
			i--;
		}
		if(a && b){
			ans+=1ll*a*b;
			a=0, b=0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
