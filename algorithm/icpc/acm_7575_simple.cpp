#include<iostream>
using namespace std;
int N, K, M[100], code[100][1000], f[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	int m=1001, n;
	for(int i=0;i<N;++i){
		cin>>M[i];
		for(int j=0;j<M[i];++j){
			cin>>code[i][j];
		}
		if(m>M[i])	m=M[i], n=i;
	}
	for(int k=0;k<m-K+1;++k){
		int j=k;
		f[k]=k;
		for(int i=k+1;i<k+K;++i){
			f[i]=k;
			while(j>k && code[n][i]!=code[n][j])	j=f[j-1];
			if(code[n][i]==code[n][j])	f[i]=++j;
		}
		int cnt=0;
		for(int t=0;t<N;++t){
			if(t==n)	continue;
			int ch=0;
			j=k;
			for(int i=0;i<M[t];++i){
				while(j>k && code[t][i]!=code[n][j])	j=f[j-1];
				if(code[t][i]==code[n][j]){
					if(j==k+K-1){
						ch=1;
						cnt++;
						break;
					}else{
						++j;
					}
				}
			}
			if(ch)	continue;
			j=k;
			for(int i=M[t]-1;~i;--i){
				while(j>k && code[t][i]!=code[n][j])	j=f[j-1];
				if(code[t][i]==code[n][j]){
					if(j==k+K-1){
						ch=1;
						cnt++;
						break;
					}else{
						++j;
					}
				}
			}
			if(!ch)	break;
		}
		if(cnt==N-1){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
