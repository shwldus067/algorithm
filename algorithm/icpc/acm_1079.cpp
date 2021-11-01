#include<iostream>
using namespace std;
int N, M, P, G[16], R[16][16], ans;
bool isdead[16];
void dfs(int k){
	if(isdead[P]){
		ans=max(ans, k);
		return;
	}
	int max, idx;
	int tmp[16];
	for(int i=0;i<N;++i){
		if(i==P)	continue;
		if(ans==M)	return;
		if(!isdead[i]){
			isdead[i]=1;	//night
			for(int j=0;j<N;++j){
				tmp[j]=G[j];
				G[j]+=R[i][j];
			}
			//day
			idx=0;
			max=-400;
			for(int j=0;j<N;++j)if(!isdead[j] && max<G[j])	idx=j, max=G[j];
			isdead[idx]=1;
			dfs(k+1);	//next day
			for(int j=0;j<N;++j)	G[j]=tmp[j];
			isdead[idx]=isdead[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=0, max, idx;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>G[i];
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>R[i][j];
	cin>>P;
	if(N&1)	t=1;	//day
	if(t){
		idx=0;
		max=G[idx];
		for(int i=1;i<N;++i)if(max<G[i])	idx=i, max=G[i];
		isdead[idx]=1;
	}
	M=N/2;
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
