#include<iostream>
using namespace std;
int N, tree[1000001];
void update(int i){
	while(i<=N){
		++tree[i];
		i+=(i&-i);
	}
}
int query(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	long long ans=0;
	int tmp;
	for(int i=0;i<N;++i){
		cin>>tmp;
		tmp=N-tmp+1;
		ans+=(long long)query(tmp);
		update(tmp);
	}
	cout<<ans<<"\n";
	return 0;
}
