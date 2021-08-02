#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, M, tree[100001], res[100001];
pii A[100000];
pii Q[100000];
pii I[100000];
void update(int i){
	while(i<=N){
		tree[i]++;
		i+=(i&-i);
	}
}
int query(int i){
	int s=0;
	while(i>0){
		s+=tree[i];
		i-=(i&-i);
	}
	return s;
}
int u_bound(int key){
	int s=0, e=N, mid;
	while(e>s){
		mid=(s+e)/2;
		if(A[mid].first<=key)	s=mid+1;
		else	e=mid;
	}
	return e;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A, A+N);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>I[i].first>>I[i].second>>Q[i].first;
		Q[i].second=i;
	}
	sort(Q, Q+M);
	int to=N, from=0;
	for(int i=M-1;i>=0;i--){
		from=u_bound(Q[i].first);
		for(int j=from;j<to;j++){
			update(A[j].second+1);
		}
		int cur=Q[i].second;
		res[cur]=query(I[cur].second)-query(I[cur].first-1);
		to=from;
	}
	for(int i=0;i<M;i++){
		cout<<res[i]<<"\n";
	}
	return 0;
}
