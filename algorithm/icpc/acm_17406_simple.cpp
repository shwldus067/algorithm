#include<iostream>
using namespace std;
int N, M, K, arr[51][51], ord[7], ans=500000, tmp[51][51];
struct Rot{
	int r, c, s;
}rot[7];
void sol(int ro){
	int tmp[51][51];
	if(ro<K){
		for(int i=1;i<N;++i)for(int j=1;j<M;++j)	tmp[i][j]=arr[i][j];
		for(int k=1;k<K;++k){
			if(!ord[k]){
				for(int i=1;i<=rot[k].s;++i){
					int r=rot[k].r-i, c=rot[k].c-i, s=i+i;
					int p=arr[r][c];
					for(int j=0;j<s;++j){
						++c;swap(arr[r][c], p);
					}
					for(int j=0;j<s;++j){
						++r;swap(arr[r][c], p);
					}
					for(int j=0;j<s;++j){
						--c;swap(arr[r][c], p);
					}
					for(int j=0;j<s;++j){
						--r;swap(arr[r][c], p);
					}
				}
				ord[k]=1;
				sol(ro+1);
				ord[k]=0;
				for(int i=1;i<N;++i)for(int j=1;j<M;++j)	arr[i][j]=tmp[i][j];
			}
		}
	}
	else{
		for(int i=1;i<N;++i){
			int tp=0;
			for(int j=1;j<M;++j){
				tp+=arr[i][j];
			}
			if(ans>tp)	ans=tp;
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
