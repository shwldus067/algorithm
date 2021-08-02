#include<iostream>
#define ll long long
using namespace std;
int N, a[1000000], t[1000000];
ll sol(int l, int r){
	if(l==r-1)	return 0;
	ll m=(l+r)/2;
	ll res1=sol(l, m);
	ll res2=sol(m, r);
	ll res3=0;
	int idx1=l, idx2=m, idx3=l;
	while(idx1 < m && idx2 < r){
		if(a[idx1] < a[idx2]){
			res3 += idx2-m;
			t[idx3++] = a[idx1++];
		}
		else{
			t[idx3++] = a[idx2++];
		}
	}
	while(idx1 < m){
		res3 += idx2-m;
		t[idx3++] = a[idx1++];
	}
	while(idx2 < r){
		t[idx3++] = a[idx2++];
	}
	for(int i = l; i < r; i++) a[i] = t[i];
	return res1+res2+res3;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	cout<<sol(0, N)<<"\n";
	return 0;
}
