#include <stdio.h>

int N;
int arr[1000050];
int tmp[1000050];

long long int solve(int l, int r){
	if(l == r-1) return 0;
	int m = (l+r)/2;
	long long int res1 = solve(l, m);
	long long int res2 = solve(m, r);
	long long int res3 = 0;

	int idx1 = l;
	int idx2 = m;
	int idx3 = l;

	while(idx1 < m && idx2 < r){
		if(arr[idx1] < arr[idx2]){
			res3 += idx2-m;
			tmp[idx3++] = arr[idx1++];
		}
		else{
			tmp[idx3++] = arr[idx2++];
		}
	}
	while(idx1 < m){
		res3 += idx2-m;
		tmp[idx3++] = arr[idx1++];
	}
	while(idx2 < r){
		tmp[idx3++] = arr[idx2++];
	}
	for(int i = l; i < r; i++) arr[i] = tmp[i];

	return res1+res2+res3;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", arr + i);
	}
	printf("%lld\n", solve(0, N));
	return 0;
}