#include<iostream>
#include<algorithm>
using namespace std;
int a[200000], b[400000], f[200000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, p, q;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>a[i];
	for(int i=0;i<N;++i)	cin>>b[i];
	sort(a, a+N);
	sort(b, b+N);
	p=a[0], q=b[0];
	for(int i=0;i<N-1;++i){
		a[i]=a[i+1]-a[i];
		b[i]=b[i+1]-b[i];
	}
	a[N-1]=p-a[N-1]+360000;
	b[N-1]=q-b[N-1]+360000;
	for(int i=0;i<N;++i)	b[i+N]=b[i];
	M=N+N-1;
	for(int i=1, j=0;i<N;++i){
		while(j && a[i]!=a[j])	--j;
		if(a[i]==a[j])	f[i]=++j;
	}
	for(int i=0, j=0;i<M;++i){
		while(j && b[i]!=a[j])	j=f[j-1];
		if(b[i]==a[j]){
			if(++j==N){
				cout<<"possible\n";
				return 0;
			}
		}
	}
	cout<<"impossible\n";
	return 0;
}
