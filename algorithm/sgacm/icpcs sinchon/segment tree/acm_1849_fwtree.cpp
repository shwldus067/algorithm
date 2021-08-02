#include<iostream>
using namespace std;
int N, tree[100001], arr[100001], M;
void update(int i, int d){
	while(i<=N){
		tree[i]+=d;
		i+=(i&-i);
	}
}
int query(int v){
	int ret=0;
	int k=1<<M;
	while(k){
		if(ret+k<=N && tree[ret+k]<v){
			v-=tree[ret+k];
			ret+=k;
		}
		k>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	update(i+1, 1);
	int tmp=1;
	while(tmp<N){
		tmp*=2;
		M++;
	}
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		t=query(t+1);
		arr[t]=i+1;
		update(t+1, -1);
	}
	for(int i=0;i<N;++i)	cout<<arr[i]<<"\n";
	return 0;
}
