#include<iostream>
using namespace std;
int N, M, K;
bool chk1[101], chk2[101];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	while(K--){
		int a, b;
		cin>>a>>b;
		if(a==1){
			chk1[b]=1;
		}
		else{
			chk2[b]=1;
		}
	}
	int nm=0, nM=0, mm=0, mM=0;
	for(int i=1;i<N;++i){
		if(chk1[i]){
			nM=max(nM, i-nm);
			nm=i;
		}
	}
	nM=max(nM, N-nm);
	for(int i=1;i<M;++i){
		if(chk2[i]){
			mM=max(mM, i-mm);
			mm=i;
		}
	}
	mM=max(mM, M-mm);
	cout<<nM*mM<<"\n";
	return 0;
}
