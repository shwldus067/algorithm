#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int tree[500001];
int sum(int i){
	int s=0;
	while(i>0){
		s+=tree[i];
		i-=(i&(-i));
	}
	return s;
}
void update(int i, int dx){
	while(i<=N){
		tree[i]+=dx;
		i+=(i&(-i));
	}
}
int main(){
	cin>>N;
	vector<pair<int, int> > a(N);
	vector<pair<int, int> > b(N);
	int c[N];
	long long s=0;
	for(int i=0;i<N;i++){
		a[i].second=i;
		cin>>a[i].first;
	}
	for(int i=0;i<N;i++){
		b[i].second=i;
		cin>>b[i].first;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0;i<N;i++){
		c[a[i].second]=b[i].second;
	}
	for(int i=0;i<N;i++){
		update(c[i]+1, 1);
		s+=i+1-sum(c[i]+1);
	}
	cout<<s<<"\n";
	return 0;
}
