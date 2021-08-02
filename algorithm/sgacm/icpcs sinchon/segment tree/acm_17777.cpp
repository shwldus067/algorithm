#include<iostream>
using namespace std;
int N, M, tree[100001], arr[100001], ans[100001];
void update(int i, int d){
	while(i<=N){
		tree[i]+=d;
		i+=(i&-i);
	}
}
int query(int d){
	int i=M, ret=0;
	while(i){
		if(ret+i<=N && tree[ret+i]<d){
			d-=tree[ret+i];
			ret+=i;
		}
		i>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];
		update(i, 1);
	}
	M=1;
	while(M<N){
		M*=2;
	}
	for(int i=N;i>0;--i){
		int t=query(arr[i]+1);
		ans[N-t]=i;
		update(t+1, -1);
	}
	for(int i=1;i<=N;++i)	cout<<ans[i]<<" ";
	return 0;
}
