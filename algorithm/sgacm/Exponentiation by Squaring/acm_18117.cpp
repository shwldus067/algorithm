#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	unsigned long long a, b, i, n;
	__int128 res, ans;
	cin>>T;
	while(T--){
		cin>>a>>b>>i>>n;
		res=1;
		ans=10;
		i--;
		while(i){
			if(i&1){
				res*=ans;
				res%=(__int128)b;
			}
			ans*=ans;
			ans%=(__int128)b;
			i>>=1;
		}
		res=(__int128)a*res%b;
		while(n--){
			ans=res*10/(__int128)b;
			cout<<(long long)ans;
			res=res*10%(__int128)b;
		}
		cout<<"\n";
	}
	return 0;
}
