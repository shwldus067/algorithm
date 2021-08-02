#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod1=822539;		
const int mod2=556211;
const int mod3=75401;
int N, M;
char A[1501], B[1501];
int p[26]={71, 83, 131, 163, 191, 307, 317, 337, 353, 383, 401, 431, 457, 479, 503, 523, 547, 569, 587, 601, 613, 683, 719, 739, 751, 787};
int m[3][26], chk1[mod1], chk2[mod2], chk3[mod3];
int init_hash(char *arr, int idx){
	ll mod=idx==2 ? mod3:idx==1 ? mod2:mod1;
	ll tmp=0;
	for(int i=0;i<N;++i){
		tmp+=m[idx][arr[i]-'a'];
		tmp%=mod;
	}
	return (int)tmp;
}
int next_hash(int hash, int idx, int s, int l, char* str){
	int mod=idx==2 ? mod3:idx==1 ? mod2:mod1;
	return (hash-m[idx][str[s-1]-'a']+m[idx][str[s+l-1]-'a']+mod)%mod;
}
int rolling_hash(){
	char *str1, *str2;
	int hs[3], hl[3], hash[3], t;
	if(N<M)	str1=A, str2=B;
	else	str1=B, str2=A, t=N, N=M, M=t;
	for(int i=0;i<3;++i){
		hs[i]=init_hash(str1, i);
		hl[i]=init_hash(str2, i);
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<3;++j)	hash[j]=hs[j];
		chk1[hash[0]]=chk2[hash[1]]=chk3[hash[2]]=N-i;
		for(int j=1;j<=i;++j){
			for(int k=0;k<3;++k){
				hash[k]=next_hash(hash[k], k, j, N-i, str1);
			}
			chk1[hash[0]]=chk2[hash[1]]=chk3[hash[2]]=N-i;
		}
		for(int j=0;j<3;++j)	hash[j]=hl[j];
		if(chk1[hash[0]]==N-i && chk2[hash[1]]==N-i && chk3[hash[2]]==N-i)
			return N-i;
		for(int j=1;j<=M-N+i;++j){
			for(int k=0;k<3;++k)	hash[k]=next_hash(hash[k], k, j, N-i, str2);
			if(chk1[hash[0]]==N-i && chk2[hash[1]]==N-i && chk3[hash[2]]==N-i)
				return N-i;
		}
		for(int j=0;j<3;++j){
			int mod=j==2 ? mod3:j==1 ? mod2:mod1;
			hs[j]=(hs[j]-m[j][str1[N-i-1]-'a']+mod)%mod;
			hl[j]=(hl[j]-m[j][str2[N-i-1]-'a']+mod)%mod;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll tp1=1, tp2=1, tp3=1;
	for(int i=0;i<26;++i){
		tp1*=p[25-i];
		tp2*=p[25-i];
		tp3*=p[25-i];
		tp1%=mod1;
		tp2%=mod2;
		tp3%=mod3;
		m[0][25-i]=(int)tp1%mod1;
		m[1][25-i]=(int)tp2%mod2;
		m[2][25-i]=(int)tp3%mod3;
	}
	cin>>A>>B;
	N=strlen(A), M=strlen(B);
	cout<<rolling_hash()<<"\n";
	return 0;
}
