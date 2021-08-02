#include<iostream>
#include<cmath>
using namespace std;
int n, seg[1<<18], size, arr[100000];
void init(int x, int s, int e){
	if(s==e)	seg[x]=s;
	else{
		int mid=(s+e)/2, nxt=x<<1;
		init(nxt, s, mid);
		init(nxt+1, mid+1, e);
		if(arr[seg[nxt]]<=arr[seg[nxt+1]])	seg[x]=seg[nxt];
		else	seg[x]=seg[nxt+1];
	}
}
int query(int x, int s, int e, int l, int r){
	if(r<s || e<l)	return -1;
	if(l<=s && e<=r)	return seg[x];
	int mid=(s+e)/2, nxt=x<<1;
	int lmin=query(nxt, s, mid, l, r);
	int rmin=query(nxt+1, mid+1, e, l, r);
	if(lmin==-1)	return rmin;
	if(rmin==-1)	return lmin;
	if(arr[lmin]<=arr[rmin])	return lmin;
	else	return rmin;
}
long long largest(int s, int e){
	int minv=query(1, 0, n-1, s, e);
	long long res=(long long)(e-s+1)*(long long)arr[minv];
	if(s<=minv-1){
		long long tmp=largest(s, minv-1);
		if(res<tmp)	res=tmp;
	}
	if(minv+1<=e){
		long long tmp=largest(minv+1, e);
		if(res<tmp)	res=tmp;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int k=(int)ceil(log2(n));
	size=(1<<(k+1));
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	init(1, 0, n-1);
	cout<<largest(0, n-1)<<"\n";
	return 0;
}
