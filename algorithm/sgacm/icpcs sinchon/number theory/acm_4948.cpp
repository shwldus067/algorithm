#include<iostream>
#include<algorithm>
using namespace std;
int N;
bool prime[246913];
int res[200000], cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	prime[1]=1;
	for(int i=2;i<246913;++i){
		if(prime[i])	continue;
		res[cnt++]=i;
		for(long long j=1ll*i*i;j<246913;j+=1ll*i){
			prime[j]=1;
		}
	}
	while(1){
		cin>>N;
		if(N==0)	break;
		cout<<lower_bound(res, res+cnt, 2*N+1)-upper_bound(res, res+cnt, N)<<"\n";
	}
	return 0;
}
