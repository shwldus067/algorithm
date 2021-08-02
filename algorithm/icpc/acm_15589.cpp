#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, d[100000];
pii A[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i].first>>A[i].second;
	}
	sort(A, A+N);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	int s=A[0].first, all=0;
	pq.push({A[0].second, 0});
	for(int i=1;i<N;++i){
		int t;
		while(pq.size() && (t=pq.top().first)<=A[i].first){
			if(pq.size()==1){
				d[pq.top().second]+=t-s;
			}
			all+=t-s;
			s=t;
			pq.pop();
		}
		if(t=pq.size()){
			if(s<A[i].first){
				all+=A[i].first-s;
				if(t==1){
					d[pq.top().second]+=A[i].first-s;
				}
			}
		}
		s=A[i].first;
		pq.push({A[i].second, i});
	}
	int k;
	while(k=pq.size()){
		int p=pq.top().first;
		all+=p-s;
		if(k==1){
			d[pq.top().second]+=p-s;
		}
		s=p;
		pq.pop();
	}
	int res=0;
	for(int i=0;i<N;++i){
		res=max(res, all-d[i]);
	}
	cout<<res<<"\n";
	return 0;
}
