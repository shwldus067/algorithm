#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct str{
	int p[61]={0, }, a[61]={0, }, s=0, n=0;
	void cal(){
		for(int k=0;k<60;++k){
			if(a[k] || p[k])	s=k;
			a[k]+=p[k];
			p[k+1]=a[k]/36;
			a[k]%=36;
		}
	}
	void mul(){
		for(int k=0;k<60;++k){
			a[k]*=n;
			a[k]+=p[k];
			p[k+1]=a[k]/36;
			a[k]%=36;
		}
		s=0;
		for(int k=0;k<60;++k){
			if(a[k])	s=k;
		}
	}
	bool operator<(const str &T)const{
		if(s<T.s)	return false;
		else if(s>T.s)	return true;
		for(int t=s;t>=0;--t){
			if(a[t]<T.a[t])	return false;
			else if(a[t]>T.a[t])	return true;
		}
		return false;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	char num[50][51], t[91], size[50], ch[36];
	str ans, cnt[36];
	for(int i=0;i<10;++i)	t[i+'0']=i, ch[i]='0'+i;
	for(int i=0;i<26;++i)	t[i+'A']=i+10, ch[i+10]='A'+i;
	for(int i=0;i<36;++i)	cnt[i].n=35-i;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>num[i];
		int len=strlen(num[i])-1, j, k;
		for(k=0, j=len;j>=0;--j, ++k){
			cnt[t[num[i][j]]].a[k]++;
		}
	}
	for(int i=0;i<36;++i){
		cnt[i].cal();
		for(int j=0;j<=cnt[i].s;++j)	ans.a[j]+=cnt[i].a[j]*i;
		cnt[i].mul();
	}
	cin>>K;
	sort(cnt, cnt+36);
	for(int i=0;i<K;++i){
		for(int j=0;j<=cnt[i].s;++j)	ans.a[j]+=cnt[i].a[j];
	}
	ans.cal();
	for(int j=ans.s;j>=0;--j)	cout<<ch[ans.a[j]];
	cout<<"\n";
	return 0;
}
