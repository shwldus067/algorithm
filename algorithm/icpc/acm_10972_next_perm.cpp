#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int N, arr[10000];
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", arr+i);
	if(!next_permutation(arr, arr+N))	printf("-1\n");
	else{
		for(int i=0;i<N;++i)	printf("%d ", arr[i]);
	}
	return 0;
}
