#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int N;
ll fact[501]={1, };
map<string, int> m;
string str[500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i)	fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int x;
			cin>>x;
			str[i].push_back(x+'0');
		}
		m[str[i]]++;
	}
	ll ans=1;
	for(auto &i:m){
		ans=ans*fact[i.second-1]%mod;
	}
	for(int i=0;i<N;++i){
		string t=str[i];
		t[i]='0';
		if(m.find(t)!=m.end())	ans=ans*m[t]%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
