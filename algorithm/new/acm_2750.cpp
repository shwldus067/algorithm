#include<iostream>
#include<stdlib.h>
using namespace std;
int partition(int *ary, int left, int right, int num){
	int tmp=ary[right];
	ary[right]=ary[num];
	ary[num]=tmp;
	int pivot=left;
	for(int i=left;i<right;i++){
		if(ary[i]<ary[right]){
			tmp=ary[i];
			ary[i]=ary[pivot];
			ary[pivot]=tmp;
			pivot++;
		}
	}
	tmp=ary[right];
	ary[right]=ary[pivot];
	ary[pivot]=tmp;
	return pivot;
}
void q_sort(int *ary, int left, int right){
	if(left>=right)	return;
	int a, b, c, mid;
	a=left+rand()%(right-left);
	b=left+rand()%(right-left);
	c=left+rand()%(right-left);
	if(ary[a]<=ary[b] && ary[b]<=ary[c])	mid=b;
	else if(ary[b]<=ary[a] && ary[a]<=ary[c])	mid=a;
	else	mid=c;
	a=partition(ary, left, right, mid);
	q_sort(ary, left, a-1);
	q_sort(ary, a+1, right);
}
int main(){
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++)	cin>>A[i];
	q_sort(A, 0, N-1);
	for(int i=0;i<N;i++)	cout<<A[i]<<"\n";
	return 0;
}
