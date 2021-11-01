#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	ll ans=0, num[10]={0, };
	bool first[10]={0, }, chk[10]={0, };
	char arr[13];
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr;
		first[arr[0]-'A']=1;
		ll t=1;
		for(int j=strlen(arr)-1;j>=0;j--){
			num[arr[j]-'A']+=t;
			t*=10;
		}
	}
	int m=-1;
	for(int k=0;k<10;++k){
		if(first[k])	continue;
		if(m==-1 || num[m]>num[k])	m=k;
	}
	chk[m]=1;
	for(int i=9;i;--i){
		m=-1;
		for(int k=0;k<10;++k){
			if(chk[k])	continue;
			if(m==-1 || num[m]<num[k])	m=k;
		}
		chk[m]=1;
		ans+=num[m]*i;
	}
	cout<<ans<<"\n";
	return 0;
}
