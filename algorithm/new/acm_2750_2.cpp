#include<iostream>
#include<stdlib.h>
using namespace std;
int ary[10000000];
void q_sort(int left, int right){
	if(left>=right)	return;
	int a, b, c, pivot;
	a=left+rand()%(right-left);
	b=left+rand()%(right-left);
	c=left+rand()%(right-left);
	if(ary[a]<=ary[b] && ary[b]<=ary[c])	pivot=ary[b];
	else if(ary[b]<=ary[a] && ary[a]<=ary[c])	pivot=ary[a];
	else	pivot=ary[c];
	a=left;
	b=right;
	do{
		while(ary[a]<pivot)	a++;
		while(ary[b]>pivot)	b--;
		if(a<=b){
			c=ary[a];
			ary[a]=ary[b];
			ary[b]=c;
			a++;
			b--;
		}
	}while(a<=b);
	q_sort(left, b);
	q_sort(a, right);
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)	cin>>ary[i];
	q_sort(0, N-1);
	for(int i=0;i<N;i++)	cout<<ary[i]<<"\n";
	return 0;
}
