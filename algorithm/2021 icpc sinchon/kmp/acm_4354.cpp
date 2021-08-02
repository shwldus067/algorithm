#include<iostream>
#include<cstring>
using namespace std;
int n, f[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[1000001];
	while(1){
		cin>>str;
		if(str[0]=='.')	break;
		n=strlen(str);
		int ans=1, cnt=0;
		for(int i=1, j=0;i<n;++i){
			while(j && str[i]!=str[j])	j=f[j-1];
			if(str[i]==str[j])	f[i]=++j;
			else	f[i]=0;
			if(f[i]==0)	ans++;
			else if(f[i]==1){
				ans+=cnt;
				cnt=1;
			}else	cnt++;
		}
		if(str[ans-1]!=str[n-1])	ans=n;
		cout<<n/ans<<"\n";
	}
	return 0;
}
