#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int update(vector<int> &arr, int nx, int s, int e, int i, int dx){
	if(i<s || i>e)	return arr[nx];
	if(i==s && i==e)	return arr[nx]=dx;
	int mid=(s+e)/2;
	return arr[nx]=max(update(arr, nx<<1, s, mid, i, dx), update(arr, (nx<<1)+1, mid+1, e, i, dx));
}
int query(vector<int> &arr, int nx, int s, int e, int l, int r){
	if(r<s || e<l)	return 0;
	if(l<=s && e<=r)	return arr[nx];
	int mid=(s+e)/2;
	return max(query(arr, nx<<1, s, mid, l, r), query(arr, (nx<<1)+1, mid+1, e, l, r));
}
bool comp(pair<int, int> p, pair<int, int> q){
	if(p.first!=q.first)	return p.first<q.first;
	return p.second>q.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a;
	cin>>N;
	int k=(int)ceil(log2(N));
	int size=(1<<(k+1));
	vector<int> arr(size, 0);
	pair<int, int> p[N];
	for(int i=0;i<N;i++){
		cin>>a;
		p[i]={a, i};
	}
	sort(p, p+N, comp);
	for(int i=0;i<N;i++){
		int tmp=query(arr, 1, 0, N-1, 0, p[i].second)+1;
		update(arr, 1, 0, N-1, p[i].second, tmp);
	}
	cout<<arr[1]<<"\n";
	return 0;
}
