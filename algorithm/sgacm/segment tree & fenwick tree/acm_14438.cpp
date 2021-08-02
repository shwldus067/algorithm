#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int inf=(1<<31)-1;
int init(vector<int>& tr, vector<int>& a, int nx, int s, int e){
	if(s==e)	return tr[nx]=a[s];
	return tr[nx]=min(init(tr, a, nx<<1, s, (s+e)/2), 
					init(tr, a, (nx<<1)+1, (s+e)/2+1, e));
}
int minimum(vector<int>& tr, int nx, int s, int e, int l, int r){
	if(l>e || r<s)	return inf;
	if(l<=s && e<=r)	return tr[nx];
	return min(minimum(tr, nx<<1, s, (s+e)/2, l, r), 
			minimum(tr, (nx<<1)+1, (s+e)/2+1, e, l, r));
}
int update(vector<int>& tr, int nx, int s, int e, int i, int dx){
	if(i<s || i>e)	return tr[nx];
	if(s==i && i==e)	return tr[nx]=dx;
	return tr[nx]=min(update(tr, nx<<1, s, (s+e)/2, i, dx), 
					update(tr, (nx<<1)+1, (s+e)/2+1, e, i, dx));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, a, b, c;
	cin>>N;
	int k=(int)ceil(log2(N));
	int size=(1<<(k+1));
	vector<int> seg(size);
	vector<int> A(N);
	for(int i=0;i<N;i++)	cin>>A[i];
	init(seg, A, 1, 0, N-1);
	cin>>M;
	while(M--){
		cin>>a>>b>>c;
		if(a==1){
			A[b-1]=c;
			update(seg, 1, 0, N-1, b-1, c);
		}
		else{
			cout<<minimum(seg, 1, 0, N-1, b-1, c-1)<<"\n";
		}
	}
}
