#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll pow(int b){
	ll ret=1, c=2;
	while(b){
		if(b&1)	ret=ret*c%mod;
		c=c*c%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int p=2e9, res=-1, t;
		int two=0, minus=0;
		for(int i=0;i<N;++i){
			cin>>t;
			if(t==0){
				p=2e9;
				two=minus=0;
				continue;
			}
			else if(t<0){
				++minus;
				if(t==-2)	++two;
			}
			else if(t==2)	++two;
			if(minus&1){
				if(p==2e9)	p=two;
				else if(res<two-p)	res=two-p;
			}else{
				if(res<two)	res=two;
			}
		}
		if(res<0)	cout<<"0\n";
		else	cout<<pow(res)<<"\n";
	}
	return 0;
}
