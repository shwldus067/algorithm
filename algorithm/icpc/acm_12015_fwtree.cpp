#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int N;
void update(int *arr, int i, int dx){
	while(i<=N){
		arr[i]=max(arr[i], dx);
		i+=(i&-i);
	}
}
int query(int *arr, int i){
	int res=0;
	while(i>0){
		res=max(arr[i], res);
		i-=(i&-i);
	}
	return res;
}
bool comp(pair<int, int> p, pair<int, int> q){
	if(p.first!=q.first)	return p.first<q.first;
	return p.second>q.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a;
	cin>>N;
	int arr[N+1]={0, };
	pair<int, int> p[N];
	for(int i=0;i<N;i++){
		cin>>a;
		p[i]={a, i};
	}
	sort(p, p+N, comp);
	for(int i=0;i<N;i++){
		int tmp=query(arr, p[i].second+1)+1;
		update(arr, p[i].second+1, tmp);
	}
	cout<<query(arr, N)<<"\n";
	return 0;
}
