#include<iostream>
using namespace std;
int N, K, M[100], code[100][1000], f[1000], d[100], r[1000];
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
		r[K-1]=code[n][k];
		for(int i=k+1;i<k+K;++i){
			while(j>k && code[n][i]!=code[n][j])	j=f[j-1];
			if(code[n][i]==code[n][j])	f[i]=++j;
			r[K+k-i-1]=code[n][i];
		}
		d[n]=k+1;
		for(int t=0;t<N;++t){
			if(t==n)	continue;
			j=k;
			for(int i=0;i<M[t];++i){
				while(j>k && code[t][i]!=code[n][j])	j=f[j-1];
				if(code[t][i]==code[n][j]){
					if(j==k+K-1){
						d[t]=k+1;
						break;
					}else{
						++j;
					}
				}
			}
		}
		j=0;
		for(int i=1;i<K;++i){
			f[i]=0;
			while(j>0 && r[i]!=r[j])	j=f[j-1];
			if(r[i]==r[j])	f[i]=++j;
		}
		for(int t=0;t<N;++t){
			if(t==n || d[t]==k+1)	continue;
			j=0;
			for(int i=0;i<M[t];++i){
				while(j>0 && code[t][i]!=r[j])	j=f[j-1];
				if(code[t][i]==r[j]){
					if(j==K-1){
						d[t]=k+1;
						break;
					}else{
						++j;
					}
				}
			}
		}
		int virus=true;
		for(int t=0;t<N;++t){
			if(d[t]!=k+1){
				virus=false;
				break;
			}
		}
		if(virus){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
