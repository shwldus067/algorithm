#include<iostream>
using namespace std;
int N;
int tree[500001];
int num[1000001];
int sum(int i){
	int s=0;
	while(i>0){
		s+=tree[i];
		i-=(i&-i);
	}
	return s;
}
void update(int i, int dx){
	while(i<=N){
		tree[i]+=dx;
		i+=(i&-i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int a, b;
	int c[N];
	long long s=0;
	for(int i=0;i<N;i++){
		cin>>a;
		num[a]=i;
	}
	for(int i=0;i<N;i++){
		cin>>b;
		c[i]=num[b];
	}
	for(int i=0;i<N;i++){
		update(c[i]+1, 1);
		s+=i+1-sum(c[i]+1);
	}
	cout<<s<<"\n";
}
