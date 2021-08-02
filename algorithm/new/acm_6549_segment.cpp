#include<iostream>
#include<cmath>
using namespace std;
void init(int *h, int *seg, int index, int start, int end){
	if(start==end)	seg[index]=start;
	else{
		init(h, seg, index*2, start, (start+end)/2);
		init(h, seg, index*2+1, (start+end)/2+1, end);
		if(h[seg[index*2]]<=h[seg[index*2+1]])	seg[index]=seg[index*2];
		else	seg[index]=seg[index*2+1];
	}
}
int query(int *h, int *seg, int node, int left, int right, int start, int end){
	if(right<start || end<left)	return -1;
	if(start<=left && right<=end)	return seg[node];
	int min_l=query(h, seg, node*2, left, (left+right)/2, start, end);
	int min_r=query(h, seg, node*2+1, (left+right)/2+1, right, start, end);
	if(min_l==-1)	return min_r;
	else if(min_r==-1)	return min_l;
	else{
		if(h[min_l]<=h[min_r])	return min_l;
		else	return min_r;
	}
}
long long int largest(int n, int *h, int *seg, int start, int end){
	int min_i=query(h, seg, 1, 0, n-1, start, end);
	long long res=(long long)(end-start+1)*(long long)h[min_i];
	if(start<=min_i-1){
		long long tmp=largest(n, h, seg, start, min_i-1);
		if(res<tmp)	res=tmp;
	}
	if(min_i+1<=end){
		long long tmp=largest(n, h, seg, min_i+1, end);
		if(res<tmp)	res=tmp;
	}
	return res;
}
int main(){
	int n, h[100000], a, size;
	cin>>n;
	while(n!=0){
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		a=(int)ceil(log2(n));
		size=(1<<(a+1));
		int seg[size];
		init(h, seg, 1, 0, n-1);
		cout<<largest(n, h, seg, 0, n-1)<<"\n";
		cin>>n;
	}
	return 0;
}
