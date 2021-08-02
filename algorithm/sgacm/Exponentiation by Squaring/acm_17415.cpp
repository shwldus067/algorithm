#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N, K;
	cin>>N>>K;
	if(K==1){
		cout<<"0\n";
		return 0;
	}
	vector<long long> pre10;
	vector<long long> pre1;
	int visit[K];
	fill(visit, visit+K, -1);
	int last;
	pre10.push_back(1);
	pre1.push_back(1);
	for(int i=1;;i++){
		long long x=(pre10.back()*10)%K;
		if(visit[x]!=-1){
			last=visit[x];
			break;
		}
		pre10.push_back(x);
		pre1.push_back((pre1.back()+x)%K);
		visit[x]=i;
	}
	long long size=pre10.size(), res=0;
	while(N--){
		long long a, b;
		cin>>a>>b;
		if(b<last)	res=(res*pre10[b])%K;
		else
			res=(res*pre10[last+(b-last)%(size-last)])%K;
		
		b--;
		long long ret=0;
		if(b<last)	ret+=pre1[b];
		else{
			if(last>0)
				ret+=pre1[last-1];
			b-=last;
			ret+=(b/(size-last))%K*(pre1[size-1]-pre1[last-1]+K)%K;
			ret%=K;
			ret+=(pre1[last+(b%(size-last))]-pre1[last-1]+K)%K;
			ret%=K;
		}
		ret*=a;
		ret%=K;
		res+=ret;
		res%=K;
	}
	cout<<res<<"\n";
}
