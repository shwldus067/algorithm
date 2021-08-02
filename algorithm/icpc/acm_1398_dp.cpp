#include<iostream>
using namespace std;
typedef long long ll;
int T, cnt[100], a[2]={10, 25};
ll P;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<100;i++)	cnt[i]=i;
	for(int i=0;i<2;i++){
		for(int j=a[i];j<100;j++){
			cnt[j]=min(cnt[j], cnt[j-a[i]]+1);
		}
	}
	cin>>T;
	while(T--){
		cin>>P;
		ll res=0;
		while(P){
			res+=cnt[P%100];
			P/=100;
		}
		cout<<res<<"\n";
	}
	return 0;
}
