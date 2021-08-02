#include<iostream>
using namespace std;
typedef long long ll;
int N, A[500000], B[500000];
ll fun(int s, int e){
	if(s==e)	return 0;
	int mid=(s+e)/2;
	ll res=fun(s, mid)+fun(mid+1, e);
	int i=s, j=mid+1, id=s;
	while(i<=mid || j<=e){
		if(i<=mid && (j>e || A[i]<=A[j]))
			B[id++]=A[i++];
		else{
			res+=(ll)(mid+1-i);
			B[id++]=A[j++];
		}
	}
	for(i=s;i<=e;i++)	A[i]=B[i];
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)	cin>>A[i];
	ll res=fun(0, N-1);
	cout<<res<<"\n";
	return 0;
}
