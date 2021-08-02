#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
pii fun(pii a, pii b){
	pii tmp;
	tmp.first=max(a.first, b.first);
	if(a.first>b.first)	tmp.second=max(a.second, b.first);
	else	tmp.second=max(a.first, b.second);
	return tmp;
}
pii init(vii& t, int* a, int nx, int s, int e){
	if(s==e){
		return t[nx]=make_pair(a[s], 0);
	}
	int mid=(s+e)/2;
	return t[nx]=fun(init(t, a, nx<<1, s, mid), init(t, a, (nx<<1)+1, mid+1, e));
}
pii update(vii& t, int nx, int s, int e, int i, int dx){
	if(i<s || i>e)	return t[nx];
	if(i==s && i==e){
		t[nx].first=dx;
		return t[nx];
	}
	int mid=(s+e)/2;
	return t[nx]=fun(update(t, nx<<1, s, mid, i, dx), update(t, (nx<<1)+1, mid+1, e, i, dx));
}
pii maximum(vii& t, int nx, int s, int e, int l, int r){
	if(e<l || r<s)	return make_pair(0, 0);
	if(l<=s && e<=r)	return t[nx];
	int mid=(s+e)/2;
	return fun(maximum(t, nx<<1, s, mid, l, r), maximum(t, (nx<<1)+1, mid+1, e, l, r));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, a, b, c, n, size;
	cin>>N;
	int A[N];
	n=(int)ceil(log2(N));
	size=(1<<(n+1));
	vii tree(size);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	init(tree, A, 1, 0, N-1);
	pii tmp;
	cin>>M;
	while(M--){
		cin>>a>>b>>c;
		if(a==1){
			A[b-1]=c;
			update(tree, 1, 0, N-1, b-1, c);
		}
		else{
			tmp=maximum(tree, 1, 0, N-1, b-1, c-1);
			cout<<tmp.first+tmp.second<<"\n";
		}
	}
	return 0;
}
