#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int N;
vector<pair<int, int> > A(500001);
int tree[500001]={0, }, arr[500001]={0, };
ll query(int i){
	ll ret=0;
	while(i>0){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
void update(int i){
	while(i<=N){
		tree[i]++;
		i+=(i&-i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	int t;
	ll res=0;
	A[0].first=A[0].second=0;
	for(int i=1;i<=N;i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A.begin(), A.begin()+N+1);
	for(int i=1;i<=N;i++)	arr[A[i].second]=i;
	for(int i=N;i>0;i--)	res+=query(arr[i]), update(arr[i]);
	cout<<res<<"\n";
	return 0;
}
