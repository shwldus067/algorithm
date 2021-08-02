#include<iostream>
using namespace std;
void update(int* t, int i, int dx, int n){
	while(i<=n){
		t[i]+=dx;
		i+=(i&-i);
	}
}
int sum(int* t, int i){
	int res=0;
	while(i>0){
		res+=t[i];
		i-=(i&-i);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, m, i;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int size=n+m+1;
		int idx[n+1];
		int fw[size]={0, };
		int top=n;
		for(int i=1;i<=n;i++){
			idx[i]=n-i+1;
			update(fw, i, 1, size);
		}
		while(m--){
			cin>>i;
			cout<<sum(fw, top)-sum(fw, idx[i])<<" ";
			update(fw, idx[i], -1, size);
			top++;
			idx[i]=top;
			update(fw, idx[i], 1, size);
		}
		cout<<"\n";
	}
	return 0;
}
