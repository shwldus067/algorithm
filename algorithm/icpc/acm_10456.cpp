#include<iostream>
using namespace std;
const long long inf=1e16;
int T, n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int d[10060]={0, };
		int t[10060]={0, };
		int t7=0, t30=0; 
		cin>>n;
		int a, b;
		for(int i=30;i<n+60;++i){
			int res;
			if(i<n+30)	cin>>a>>b;
			else	a=b=0;
			t[i]=b;
			t7-=t[i-7];
			t7+=b+b; 
			t30=0;
			int cnt=0;
			for(int j=i-29;j<=i;++j){
				if(t[j]>3){
					t30+=6;
					++cnt;
				}
				else{
					t30+=t[j]+t[j];
					cnt=0;
				}
				if(cnt>6)	t30-=6, cnt=0;
			}
			res=d[i-1]+a+b+b;
			res=min(res, d[i-1]+3+b+b);
			res=min(res, d[i-1]+6);
			res=min(res, d[i-7]+18+t7);
			res=min(res, d[i-7]+36);
			res=min(res, d[i-30]+45+t30);
			res=min(res, d[i-30]+90);
			d[i]=res;
		}
		cout<<d[n+59]<<"\n";
	}
	return 0;
}
