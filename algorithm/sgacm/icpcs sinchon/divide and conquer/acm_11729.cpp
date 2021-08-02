#include<cstdio>
using namespace std;
int N;
void sol(int n, int f, int t){
	if(n!=0){
		sol(n-1, f, 6-f-t);
		printf("%d %d\n", f, t);
		sol(n-1, 6-f-t, t);
	}
}
int main(){
	scanf("%d", &N);
	printf("%d\n", (1<<N)-1);
	sol(N, 1, 3);
	return 0;
}
