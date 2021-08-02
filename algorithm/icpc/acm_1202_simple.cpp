#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, a, b, s;
	long long res=0;
	cin>>N>>K;
	pair<int, int> jw[N];
	int bag[K];
	priority_queue<int> pq;
	for(int i=0;i<N;i++){
		cin>>jw[i].first>>jw[i].second;
	}
	for(int i=0;i<K;i++){
		cin>>bag[i];
	}
	sort(jw, jw+N);
	sort(bag, bag+K);
	int idx=0;
	for(int i=0;i<K;i++){
		while(idx<N && jw[idx].first<=bag[i]){
			pq.push(jw[idx].second);
			idx++;
		}
		if(!pq.empty()){
			res+=pq.top();
			pq.pop();
		}
	}
	cout<<res<<"\n";
	return 0;
}
