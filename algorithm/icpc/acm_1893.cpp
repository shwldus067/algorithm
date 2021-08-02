#include<iostream>
#include<cstring>
using namespace std;
int N, f[50005], ans[63];
char A[64], W[50005], S[500005], num[256];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N--){
		cin>>A>>W>>S;
		int a=strlen(A), w=strlen(W), s=strlen(S);
		for(int i=0;i<a;++i)	num[A[i]]=i;
		int j=0, idx=0;
		for(int i=1;i<w;++i){
			while(j>0 && W[i]!=W[j])	j=f[j-1];
			if(W[i]==W[j])	f[i]=++j;
		}
		for(int k=0;k<a;++k){
			j=0;
			int cnt=0;
			for(int i=0;i<s;++i){
				char tp=A[(num[S[i]]-k+a)%a];
				while(j>0 && tp!=W[j])	j=f[j-1];
				if(tp==W[j]){
					if(j==w-1){
						cnt++;
						j=f[j];
					}else{
						++j;
					}
				}
			}
			if(cnt==1){
				ans[idx++]=k;
			}
		}
		if(idx){
			if(idx>1)	cout<<"ambiguous: ";
			else	cout<<"unique: ";
			for(int i=0;i<idx;++i)	cout<<ans[i]<<" ";
		}
		else	cout<<"no solution";
		cout<<"\n";
	}
}
