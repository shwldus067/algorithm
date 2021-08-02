#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	ll arr[10000];
	cin>>t;
	while(t--){
		cin>>n;
		vector<string> vec(n);
		for(int i=0;i<n;++i)	cin>>vec[i];
		sort(vec.begin(), vec.end());
		bool chk=true;
		for(int i=1;i<n;++i){
			if(vec[i-1]==vec[i].substr(0, vec[i-1].size()))
				chk=false;
		}
		if(chk)	cout<<"YES\n";
		else	cout<<"NO\n";
	}
	return 0;
}
