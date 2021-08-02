#include<iostream>
#include<algorithm>
using namespace std;
int N, K, a[5000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i)	cin>>a[i];
	nth_element(a, a+K-1, a+N);
	cout<<a[K-1]<<"\n";
	return 0;
}
