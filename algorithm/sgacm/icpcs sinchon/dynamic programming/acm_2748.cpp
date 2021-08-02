#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	long long fib[N+1]={0, 1};
	for(int i=2;i<=N;++i){
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<fib[N]<<"\n";
	return 0;
}
