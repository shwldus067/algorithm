#include<iostream>
#include<algorithm>
using namespace std;
int binsearch(int *ary, int num, int left, int right){
	if(left>right)	return 0;
	int mid=(left+right)/2;
	if(ary[mid]==num)	return 1;
	else if(ary[mid]<num)	return binsearch(ary, num, mid+1, right);
	else	return binsearch(ary, num, left, mid-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, tmp;
	cin>>N;
	int card[N];
	for(int i=0;i<N;i++){
		cin>>card[i];
	}
	sort(card, card+N);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		cout<<binsearch(card, tmp, 0, N-1)<<" ";
	}
}
