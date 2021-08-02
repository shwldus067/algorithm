#include<iostream>
using namespace std;
int N;
bool check[4000001];
int prime[300000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	int idx=0;
	for(long long i=2;i<=N;i++){
		if(check[i])	continue;
		prime[idx++]=i;
		for(long long j=i*i;j<=N;j+=i){
			check[j]=true;
		}
	}
	int s=0, e=0, sum=0, cnt=0;
	while(1){
		if(sum>=N)	sum-=prime[s++];
		else if(e==idx)	break;
		else	sum+=prime[e++];
		if(sum==N)	cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
