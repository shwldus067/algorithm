#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int init(vector<int>&t, vector<int>& a, int nx, int s, int e){
	if(s==e)	return t[nx]=s;
	int l=init(t, a, (nx<<1), s, (s+e)/2);
	int r=init(t, a, (nx<<1)+1, (s+e)/2+1, e);
	if(a[l]<=a[r])	return t[nx]=l;
	else	return t[nx]=r;
}
int update(vector<int>& t, vector<int>& a, int nx, int s, int e, int i){
	if(i<s || i>e)	return t[nx];
	if(i==s && i==e)	return t[nx]=i;
	int l=update(t, a, nx<<1, s, (s+e)/2, i);
	int r=update(t, a, (nx<<1)+1, (s+e)/2+1, e, i);
	if(a[l]<=a[r])	return t[nx]=l;
	else	return t[nx]=r;
}
int minimum(vector<int> &t, vector<int>& a, int nx, int s, int e, int l, int r){
	if(l<=s && e<=r)	return t[nx];
	int mid=(s+e)/2;
	if(mid<l){
		return minimum(t, a, (nx<<1)+1, mid+1, e, l, r);
	}
	else if(r<=mid){
		return minimum(t, a, nx<<1, s, mid, l, r);
	}
	else{
		int i=minimum(t, a, nx<<1, s, mid, l, r);
		int j=minimum(t, a, (nx<<1)+1, mid+1, e, l, r);
		if(a[i]<=a[j])	return i;
		else	return j;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, n, size, a, b, c;
	cin>>N;
	n=(int)ceil(log2(N));
	size=(1<<(n+1));
	vector<int> seg(size);
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	init(seg, A, 1, 0, N-1);
	cin>>M;
	while(M--){
		cin>>a>>b>>c;
		if(a==1){
			A[b-1]=c;
			update(seg, A, 1, 0, N-1, b-1);
		}
		else{
			cout<<minimum(seg, A, 1, 0, N-1, b-1, c-1)+1<<"\n";
		}
	}
	return 0;
}
