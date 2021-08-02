#include <stdio.h>

int N;
int arr[100050];

long long int __min(long long int a, long long int b){
	return (a<b)?a:b;
}

long long int __max(long long int a, long long int b){
	return (a>b)?a:b;
}

long long int solve(int l, int r){
	if(l == r) return 1LL*arr[l]*arr[l];
	int m = (l+r)/2;
	long long int res1 = solve(l, m);
	long long int res2 = solve(m+1, r);
	long long int min_val = __min(arr[m], arr[m+1]);
	long long int sum = arr[m] + arr[m+1];
	long long int res3 = min_val*sum;
	int idx1 = m;
	int idx2 = m+1;
	while(l < idx1 && idx2 < r){
		if(arr[idx1-1] < arr[idx2+1]){
			idx2++;
			min_val = __min(min_val, arr[idx2]);
			sum += arr[idx2];
		}
		else{
			idx1--;
			min_val = __min(min_val, arr[idx1]);
			sum += arr[idx1];
		}
		res3 = __max(res3, sum*min_val);
	}
	while(l < idx1){
		idx1--;
		min_val = __min(min_val, arr[idx1]);
		sum += arr[idx1];
		res3 = __max(res3, sum*min_val);
	}
	while(r > idx2){
		idx2++;
		min_val = __min(min_val, arr[idx2]);
		sum += arr[idx2];
		res3 = __max(res3, sum*min_val);
	}
	return __max(res1, __max(res2, res3));
}

int main(){

	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", arr+i);

	printf("%lld\n", solve(0, N-1));
}