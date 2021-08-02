#include <stdio.h>

int arr[1000050];
int tmp[1000050];
int N;



void merge(int l, int m, int r){
	int lidx = l;
	int ridx = m;
	int tidx = l;
	while(lidx < m && ridx < r){
		if(arr[lidx] < arr[ridx]) tmp[tidx++] = arr[lidx++];
		else tmp[tidx++] = arr[ridx++];
	}

	while(lidx < m) tmp[tidx++] = arr[lidx++];
	while(ridx < r) tmp[tidx++] = arr[ridx++];

	for(int i = l; i < r; i++) arr[i] = tmp[i];
}

void merge_sort(int l, int r){
	if(l == r-1) return;
	int m = (l+r)/2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", arr+i);
	merge_sort(0, N);

	for(int i = 0; i < N; i++) printf("%d ", arr[i]);
	puts("");

	return 0;
}