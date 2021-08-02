#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct _node{
	int start;
	int finish;
}node;

int partition(node *ary, int left, int right){
	int i, j, k, pivot, s, f, a, b, c;
	
	i=(rand()%(right-left+1))+left;
	j=(rand()%(right-left+1))+left;
	k=(rand()%(right-left+1))+left;
	a=ary[i].finish;
	b=ary[j].finish;
	c=ary[k].finish;
	if(a<=b && b<=c)	a=j;
	else if(b<=c && c<=a)	a=k;
	else	a=i;
	
	s=ary[a].start;
	f=ary[a].finish;
	ary[a].start=ary[right].start;
	ary[a].finish=ary[right].finish;
	ary[right].start=s;
	ary[right].finish=f;
	
	pivot=left;
	for(i=left;i<right;i++){
		if(ary[i].finish<ary[right].finish || (ary[i].finish==ary[right].finish && ary[i].start<ary[right].start)){
			s=ary[i].start;
			f=ary[i].finish;
			ary[i].start=ary[pivot].start;
			ary[i].finish=ary[pivot].finish;
			ary[pivot].start=s;
			ary[pivot].finish=f;
			pivot++;
		}
	}
	s=ary[i].start;
	f=ary[i].finish;
	ary[i].start=ary[pivot].start;
	ary[i].finish=ary[pivot].finish;
	ary[pivot].start=s;
	ary[pivot].finish=f;
	return pivot;
}

void quick_sort(node *ary, int left, int right){
	int pivot;
	if(right-left>0){
		pivot=partition(ary, left, right);
		quick_sort(ary, left, pivot-1);
		quick_sort(ary, pivot+1, right);
	}
}

int main(){
	int N, cnt, tmp;
	cin>>N;
	node meeting[N];
	for(int i=0;i<N;i++){
		cin>>meeting[i].start>>meeting[i].finish;
	}
	quick_sort(meeting, 0, N-1);
	cnt=1;
	tmp=0;
	for(int i=1;i<N;i++){
		if(meeting[i].start>=meeting[tmp].finish){
			cnt++;
			tmp=i;
		}
	}
	cout<<cnt;
	return 0;
}
