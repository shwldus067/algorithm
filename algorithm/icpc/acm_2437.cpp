#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int N, arr[1000];
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", arr+i);
	sort(arr, arr+N);
	int ans=0;
	for(int i=0;i<N;++i){
		if(ans+1<arr[i])	break;
		ans+=arr[i];
	}
	printf("%d\n", ans+1);
	return 0;
}
