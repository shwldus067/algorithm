#include<iostream>
using namespace std;
int N, M, K, arr[51][51], ord[7], ans=500000, tmp[51][51];
struct Rot{
	int r, c, s;
}rot[7];
void rotate(int k){
	for(int i=1;i<=rot[k].s;++i){
		int r=rot[k].r-i, c=rot[k].c-i, s=i+i;
		int p=tmp[r][c], t;
		for(int j=0;j<s;++j){
			++c;
			t=tmp[r][c], tmp[r][c]=p,p=t;
		}
		for(int j=0;j<s;++j){
			++r;
			t=tmp[r][c], tmp[r][c]=p,p=t;
		}
		for(int j=0;j<s;++j){
			--c;
			t=tmp[r][c], tmp[r][c]=p,p=t;
		}
		for(int j=0;j<s;++j){
			--r;
			t=tmp[r][c], tmp[r][c]=p,p=t;
		}
	}
}
void sol(int k){
	if(k==K){
		for(int i=1;i<N;++i)for(int j=1;j<M;++j)	tmp[i][j]=arr[i][j];
		for(int i=1;i<K;++i){
			rotate(ord[i]);
		}
		int res=500000;
		for(int i=1;i<N;++i){
			int tp=0;
			for(int j=1;j<M;++j){
				tp+=tmp[i][j];
			}
			if(res>tp)	res=tp;
		}
		if(ans>res)	ans=res;
		return;
	}
	for(int i=1;i<K;++i){
		if(!ord[i]){
			ord[i]=k;
			sol(k+1);
			ord[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	++N, ++M, ++K;
	for(int i=1;i<N;++i){
		for(int j=1;j<M;++j)	cin>>arr[i][j];
	}
	for(int i=1;i<K;++i)	cin>>rot[i].r>>rot[i].c>>rot[i].s;
	sol(1);
	cout<<ans<<"\n";
	return 0;
}
