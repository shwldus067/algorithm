#include<iostream>
using namespace std;
typedef long long ll;
int T, N, M, K;
bool _hash[10000];
char str[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M>>K>>str;
		if(K==1){
			for(int i=0;i<M;++i)	cout<<'a';
			cout<<"\n";
			continue;
		}
		for(int i=0;i<10000;++i)	_hash[i]=0;
		for(int i=0;i<N-M+1;++i){
			ll key=0;
			int p=1;
			for(int j=0;j<M;++j){
				key+=(str[i+j]-'a')*p;
				if(key>=10000)	break;
				p*=K;
				if(p>=10000)	break;
			}
			if(key<10000)	_hash[key]=1;
		}
		for(int i=0;i<10000;++i){
			if(!_hash[i]){
				char ans[M+1];
				for(int j=0;j<M;++j){
					ans[j]='a'+i%K;
					i/=K;
				}
				ans[M]=0;
				cout<<ans<<"\n";
				break;
			}
		}
	}
	return 0;
}
