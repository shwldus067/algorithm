#include<iostream>
using namespace std;
int main(){
	int M, N;
	cin>>M>>N;
    int prime[N+1]={0};
	prime[1]=1;
	for(int i=2;i<=N;i++){
		if(prime[i]==0){
			if(i>=M)
				cout<<i<<"\n";
			for(long long j=(long long)i*i;j<=N;j+=i){
				prime[j]=1;
			}
		}
	}
	return 0;
}

