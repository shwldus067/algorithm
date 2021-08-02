#include<iostream>
#include<vector>
using namespace std;
bool chk[20];
vector<int> v[20];
int v2[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, M, a=0, b=1, i, j, t, k;
	cin>>N>>K;
	for(i=0;i<N;++i){
		M=K+i;
		for(j=0, t=1;t<=M;++j){
			if(M&t){
				if(!chk[j])	++a, chk[j]=1;
				v[j].push_back(i+1);
			}
			t*=2;
		}
	}
	M=N-1;
	t=1;
	while(t<=M)	++b, t*=2;
	if(a<b){
		cout<<a<<"\n";
		for(i=0;i<20;++i){
			if(t=v[i].size()){
				cout<<t<<" "<<(1<<i)<<"\n";
				for(j=0;j<t;++j)	cout<<v[i][j]<<" ";
				cout<<"\n";
			}
		}
	}
	else{
		cout<<b<<"\n";
		cout<<N<<" "<<K<<"\n";
		for(i=0;i<N;++i)	cout<<i+1<<" ";
		cout<<"\n";
		for(i=0;i<18;++i){
			t=0, k=1<<i;
			for(j=1;j<N;++j){
				if(j&k)	v2[t++]=j+1;
			}
			if(!t)	continue;
			cout<<t<<" "<<k<<"\n";
			for(j=0;j<t;++j)	cout<<v2[j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
