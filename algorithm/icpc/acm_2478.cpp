#include<iostream>
using namespace std;
int N, arr[500], a[500], k1, p, q, k2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		arr[i]%=N;
	}
	int i=1, j=0;
	for(;i<N && arr[i]!=(arr[i-1]+1)%N;++i);
	--i;
	k2=N-i;
	for(;i<N;++j, ++i)	a[j]=arr[i];
	for(i=0;j<N;++j, ++i)	a[j]=arr[i];
	for(i=0;i<N-1 && a[i+1]==(a[i]+1)%N;++i);
	p=i;
	for(;i<N && a[i]!=(a[p]+1)%N;++i);
	q=i;
	int n=(q-p)/2, t;
	++p;
	for(i=0;i<n;++i){
		t=a[p+i], a[p+i]=a[q-i], a[q-i]=t;
	}
	for(i=0;i<N && a[i]!=1;++i);
	k1=N-i;
	cout<<k1<<"\n"<<p+1<<" "<<q+1<<"\n"<<k2<<"\n";
	return 0;
}
