#include<iostream>
using namespace std;
typedef long long ll;
int n, k;
char str[15][51];
int m[15], l[15], p[101][51];
bool ch[1<<15];
ll dp[1<<15][100];
int modulo(int r, int x){
	int s=r;
	if(p[r][x]<0){
		for(int i=0;i<x;i++)	s=(s*10)%k;
		p[r][x]=s;
	}
	return p[r][x];
}
ll f(int s){
	if(!ch[s]){
		if(s==0){
			dp[0][0]=1;
			ch[0]=true;
			return 0;
		}
		int t;
		for(int i=0;i<n;i++){
			if(s&(1<<i)){
				t=s&(~(1<<i));
				f(t);
				for(int j=0;j<k;j++){
					dp[s][(modulo(j, l[i])+m[i])%k]+=dp[t][j];
				}
			}
		}
	}
	ch[s]=true;
	return 0;
}
ll gcd(ll a, ll b){
	return b? gcd(b, a%b):a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)	cin>>str[i];
	cin>>k;
	int mod, j;
	for(int i=0;i<n;i++){
		mod=0;
		for(j=0;str[i][j]!=0;j++){
			mod=(mod*10+str[i][j]-'0')%k;
		}
		m[i]=mod;
		l[i]=j;
	}
	fill(&p[0][0], &p[100][51], -1);
	f((1<<n)-1);
	ll a, b, c;
	a=1;
	for(ll i=2;i<=n;i++)	a*=i;
	b=dp[(1<<n)-1][0];
	c=gcd(a, b);
	cout<<b/c<<"/"<<a/c<<"\n";
	return 0;
}
