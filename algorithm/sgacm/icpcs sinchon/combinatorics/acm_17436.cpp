#include<iostream>
using namespace std;
int N;
long long M;
int prime[10];
long long sol(int bit, int n, int id){
	long long ans=0, cur=1, tmp=0;
	for(int i=0;i<N;++i){
		if(bit&(1<<i)){
			cur*=1ll*prime[i];
		}
		else if(i>=id){
			ans+=sol(bit|(1<<i), n+1, i+1);
		}
	}
	if(cur!=1){
		tmp=M/cur;
	}
	if(n&1){
		return ans+tmp;
	}
	else{
		return ans-tmp;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>prime[i];
	}
	cout<<sol(0, 0, 0)<<"\n";
	return 0;
}
