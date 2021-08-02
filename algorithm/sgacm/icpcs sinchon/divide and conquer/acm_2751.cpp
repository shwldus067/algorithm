#include<iostream>
using namespace std;
int N, a[1000000], t[1000000];
void merge(int l, int m, int r){
	int idx1=l, idx2=m, idx3=l;
	while(idx1<m && idx2<r){
		if(a[idx1]<a[idx2]){
			t[idx3++]=a[idx1++];
		}
		else{
			t[idx3++]=a[idx2++];
		}
	}
	while(idx1<m){
		t[idx3++]=a[idx1++];
	}
	while(idx2<r){
		t[idx3++]=a[idx2++];
	}
	for(int i=l;i<r;++i)	a[i]=t[i];
}
void merge_sort(int l, int r){
	if(l==r-1){
		t[l]=a[l];
		return;
	}
	int m=(l+r)/2;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	merge_sort(0, N);
	for(int i=0;i<N;++i){
		cout<<a[i]<<"\n";
	}
	return 0;
}
