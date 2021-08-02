#include<iostream>
#include<algorithm>
using namespace std;
int binsearch(int *A, int n, int left, int right){
	if(left>right)	return 0;
	int mid=(left+right)/2;
	if(A[mid]==n)	return 1;
	if(A[mid]<n)	return binsearch(A, n, mid+1, right);
	else	return binsearch(A, n, left, mid-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, tmp;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	sort(A, A+N);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		cout<<binsearch(A, tmp, 0, N-1)<<"\n";
		/*if(binary_search(A, A+N, tmp)) cout<<1<<"\n";
		else	cout<<0<<"\n";
		*/
	}
}
